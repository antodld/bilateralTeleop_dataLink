#include "../include/bilateralTeleop_dataLink/receiver.h"

namespace bilateralTeleop
{

namespace dataLink
{

// template <typename T>
// void receiver<T>::update()
// {
//    data_ = receiveSerializedObject(socket_);
// }

// template <typename T>
// T receiver<T>::receiveSerializedObject(const int socket)
// {
//     size_t dataSize;
//     recv(socket, &dataSize, sizeof(dataSize), 0);
//     char buffer[dataSize + 1];
//     recv(socket, buffer, dataSize, 0);
//     buffer[dataSize] = '\0';
//     std::string serializedData(buffer);
//     return deserializeObject<T>(serializedData).data;
// }

// template <typename T>
// void receiver(const char* ip, const int port)
// {
//     // create a socket
//     socket_ = socket(AF_INET, SOCK_STREAM, 0);
    
//     // specify the server address and port
//     struct sockaddr_in server_address;
//     server_address.sin_family = AF_INET;
//     server_address.sin_addr.s_addr = INADDR_ANY;
//     server_address.sin_port = htons(port);
    
//     // bind the socket to the server address and port
//     bind(socket_, (struct sockaddr *)&server_address, sizeof(server_address));
    
//     // listen for incoming connections
//     listen(socket_, 3);
    
//     // accept incoming connections
//     int client_socket;
//     struct sockaddr_in client_address;
//     socklen_t addrlen = sizeof(client_address);
//     client_socket = accept(socket_, (struct sockaddr *)&client_address, &addrlen);
    
//     // send data to the client
//     const char *message = "Hello, client!";
//     send(client_socket, message, strlen(message), 0);
    
//     // // receive data from the client
//     // char buffer[1024] = {0};
//     // read(client_socket, buffer, 1024);
//     // std::cout << "Client message: " << buffer << std::endl;
    
// }

template <typename T>
void receiver<T>::dummy()
{
    int a = 0;
}

} // namespace bilateralTeleop

} // namespace datalink