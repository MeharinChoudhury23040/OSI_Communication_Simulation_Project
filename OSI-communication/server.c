#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

void decapsulate(char *data)
{
    char *start = strstr(data, "APP{");

    if (start)
    {
        start += 4;

        char *end = strchr(start, '}');

        if (end)
            *end = '\0';

        printf("\nFinal Message:\n%s\n", start);
    }
    else
    {
        printf("Invalid encapsulated data!\n");
    }
}

int main()
{
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server, client;

    int c;
    char buffer[1024];

    WSAStartup(MAKEWORD(2, 2), &wsa);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    bind(server_socket, (struct sockaddr*)&server, sizeof(server));

    listen(server_socket, 3);

    printf("Server Waiting...\n");

    c = sizeof(struct sockaddr_in);

    client_socket = accept(server_socket,
                           (struct sockaddr*)&client,
                           &c);

    int bytes = recv(client_socket, buffer, sizeof(buffer) - 1, 0);

    if (bytes > 0)
    {
        buffer[bytes] = '\0';

        printf("\nReceived Encapsulated Data:\n%s\n", buffer);

        decapsulate(buffer);
    }

    closesocket(client_socket);
    closesocket(server_socket);

    WSACleanup();

    return 0;
}