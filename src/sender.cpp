#include "../include/bilateralTeleop_dataLink/sender.h"

namespace bilateralTeleop
{

namespace dataLink
{
//template <typename T>
// sender<T>::sender(const char* ip, const int port)
// {
    // server_IP_ = ip;
    // socket_ = socket(AF_INET, SOCK_STREAM, 0);
    // struct sockaddr_in serverAddr;
    // serverAddr.sin_family = AF_INET;
    // serverAddr.sin_port = htons(port);
    // inet_pton(AF_INET, server_IP_, &(serverAddr.sin_addr));
// }



// template <typename T>
// void sender<T>::sendSerializedObject(const SerializableClass<T>& obj) {
//     std::string serializedData = serializeObject(obj);
//     const char* data = serializedData.c_str();
//     size_t dataSize = serializedData.size();

//     send(socket_, &dataSize, sizeof(dataSize), 0);
//     send(socket_, data, dataSize, 0);
// }

} // namespace bilateralTeleop

} // namespace datalink

