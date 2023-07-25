#pragma once
#ifndef RECEIVER_H
#define RECEIVER_H
#include "motion.h"
#include "serialize.h"
#include "transformation.h"
#include <iostream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <thread>
#include <errno.h>
#include <fcntl.h>


namespace bilateralTeleop
{

namespace dataLink
{
template <typename T>
class receiver
{

public:
    receiver()
    {
        // receiver(server_IP_,server_port_);
    }

    void create(const int port)
    {
        server_port_ = port;
        // Create a UDP socket
        socket_ = socket(AF_INET, SOCK_DGRAM, 0);
        
        // specify the server address and port
        struct sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_port = htons(server_port_);
        
        // bind the socket to the server address and port
        bind(socket_, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
  

        connected_ = true;

    }
    
    int get(T & data)
    {
        int res = update();
        data = data_;
        return res;
    }
    
    ~receiver()
    {
        // close the socket
        close(socket_);
    }
    bool connected()
    {
        return connected_;
    }

private:
    int update()
    {
        if(connected_)
        {
          return receiveSerializedObject();
        }
        return 1;
    }
    void dummy();
    int receiveSerializedObject()
    {
 
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);

        size_t dataSize;

        int flags = fcntl(socket_, F_GETFL);
        fcntl(socket_, F_SETFL, flags | O_NONBLOCK);

        int recvStatus = recvfrom(socket_, &dataSize, sizeof(dataSize), 0,
                                    (struct sockaddr*)&clientAddr, &clientAddrLen);

        if (recvStatus == -1) {
            // std::cout << "No new data available at the moment." << std::endl;
            // Return an empty object to indicate no new data.
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
                return 1;
            }

            // Error occurred while receiving data.
            // You can handle the error accordingly.
            std::cerr << "Error in recvfrom: " << strerror(errno) << std::endl;

            // For this example, we'll return an empty object.
            return 1;
        } 

        char buffer[dataSize + 1];
        recvfrom(socket_, buffer, dataSize, 0,
                (struct sockaddr*)&clientAddr, &clientAddrLen);
        buffer[dataSize] = '\0';
        std::string serializedData(buffer);
        data_ = deserializeObject<T>(serializedData).data;
        return 0;
    }

    T data_;
    int server_port_ = 12345;
    int socket_;
    bool connected_ = false;

};
} // namespace bilateralTeleop

} // namespace datalink
#endif 