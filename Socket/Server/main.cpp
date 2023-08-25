#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cout << "Failed to initialize winsock" << std::endl;
        return 1;
    }
    // 创建服务器套接字
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET)
    {
        std::cout << "Failed to create socket" << std::endl;
        WSACleanup();
        return 1;
    }

    // 绑定IP地址和端口号
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9527); // 设置端口号
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(serverSocket, (sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cout << "Failed to bind address to the socket" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // 监听和接受连接请求
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cout << "Failed to listen" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Waiting for client connection..." << std::endl;

    // 接受客户端连接
    SOCKET clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET)
    {
        std::cout << "Failed to accept client connection" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Client connected" << std::endl;

    // 与客户端进行数据通信
    char buffer[1024];
    int bytesReceived;
    while (true)
    {
        // 接收客户端发送的数据
        bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0)
        {
            std::cout << "Client disconnected" << std::endl;
            break;
        }

        // 处理接收到的数据
        std::cout << "Received: " << buffer << std::endl;

        // 回复客户端
        send(clientSocket, buffer, bytesReceived, 0);
    }

    // 关闭套接字和清理Winsock库
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
