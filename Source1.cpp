//#include <arpa/inet.h>
//#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sys/socket.h>
//#include <unistd.h>
#include <ws2tcpip.h>
#include <iostream>
#include <windows.h>
#include <winsock2.h>

#pragma comment (lib,"ws2_32.lib")

using namespace std;


#define PORT 58975

// Driver code
int main()
{
    WSADATA wsaData;
    int iResult;

    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char str[100];

    string s = "hello";
    for (int i = 0; i < 5; i++) 
    {
        str[i] = s[i];
    }

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    char buffer[1024] = { 0 };

    // Creating socket file descriptor
    if ((sock = socket(AF_INET,
        SOCK_STREAM, 0))
        < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from
    // text to binary form 127.0.0.1 is local
    // host IP address, this address should be
    // your system local host IP address
    if (inet_pton(AF_INET, "192.168.178.56",
        &serv_addr.sin_addr)
        <= 0) {
        printf("\nAddress not supported \n");
        return -1;
    }

    // connect the socket
    if (connect(sock, (struct sockaddr*)&serv_addr,
        sizeof(serv_addr))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    int l = sizeof(str);

    // send string to server side
    send(sock, str, sizeof(str), 0);


    return 0;
}
