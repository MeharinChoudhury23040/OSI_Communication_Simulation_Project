#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server;

    char message[] = "APP{Hello from Client}";
    
    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Winsock initialization failed!\n");
        return 1;
    }

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket == INVALID_SOCKET)
    {
        printf("Socket creation failed!\n");
        WSACleanup();
        return 1;
    }

    // Server configuration
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8888);

    // Connect to server
    if (connect(client_socket, (struct sockaddr*)&server,
                sizeof(server)) == SOCKET_ERROR)
    {
        printf("Connection failed! Error: %d\n", WSAGetLastError());

        closesocket(client_socket);
        WSACleanup();
        return 1;
    }

    printf("Connected to Server Successfully!\n");

    // Send encapsulated data
    if (send(client_socket, message, strlen(message), 0) == SOCKET_ERROR)
    {
        printf("Message sending failed!\n");
    }
    else
    {
        printf("Message Sent: %s\n", message);
    }

    closesocket(client_socket);
    WSACleanup();

    return 0;
}