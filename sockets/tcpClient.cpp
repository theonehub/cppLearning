#include <iostream>
#include "tcpClient.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

tcpClient::~tcpClient()
{
    close(mFd);
}

int tcpClient::connectSrv(string& serverIP, int serverPort)
{
    struct sockaddr_in srvAddress;
    int connected = -1;

    mServerIP = serverIP;
    mServerPort = serverPort;
    mFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (mFd < 0)
    {
        cout << "Error: Not able to create Socket" << endl;
        return -1;
    }

    srvAddress.sin_family = AF_INET;
    srvAddress.sin_port = htons(mServerPort);

    if (inet_pton(AF_INET, serverIP.c_str(), &srvAddress.sin_addr) <= 0)
    {
        cout << "Error : address invalid" << endl;
        close(mFd);
        return -1;
    }

    connected = connect(mFd, (struct sockaddr*) &srvAddress, sizeof(srvAddress));
    if (connected < 0)
    {
        perror("Connection");
        cout << "Error : Connection to server Failed!!!" << endl;
        close(mFd);
        return -1;
    }
    return mFd;
}

int tcpClient::sendData(int fd, string& data)
{
    cout << "Error : " << data.c_str() << " " << data.length() << endl;
    int bytesSend = send(fd, data.c_str(), data.length(), 0);
    perror("Send");
    cout << "bytesSend : "<< bytesSend << endl;
}