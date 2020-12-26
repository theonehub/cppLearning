#include "tcpServer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

tcpServer::~tcpServer()
{
    close(mFd);
}

int tcpServer::getFd()
{
    return mFd;
}

bool tcpServer::connect()
{
    int opt = 1;
    struct sockaddr_in address;

    mFd = socket(AF_INET, SOCK_STREAM, 0);
    if (0 == mFd)
    {
        cout << "Error : Socket Failed!!!" << endl;
        return false;
    }

    if (setsockopt(mFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        perror("Socket");
        cout << "Error : Socket Option Failed!!!" << endl;
        close(mFd);
        return false;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(mPort);

    if (bind(mFd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        cout << "Error : Socket Bind Failed!!!" << endl;
        close(mFd);
        return false;
    }

    if (listen(mFd, mQueueCount) < 0)
    {
        cout << "Error : Socket listen Failed!!!" << endl;
        close(mFd);
        return false;
    }
    return true;
}

void tcpServer::readData()
{
    struct sockaddr_in srcAddress;
    int addrLen = sizeof(srcAddress);
    int newSocket = -1;
    
    while (newSocket < 0)
    {
        newSocket = accept(mFd, (struct sockaddr*)&srcAddress, (socklen_t*)&addrLen);
        if (newSocket < 0)
        {
            cout << "Error : accept Failed!!!" << endl;
            continue;
        }
        printf("Port %d", srcAddress.sin_port);
        int bytesRecvd = 0;
        //while (bytesRecvd >= 0)
        {
            char buffer[1024] = {0};
            bytesRecvd = read(newSocket, buffer, 1024);
            cout << "bytesRecvd " << bytesRecvd << endl;
            printf("DataRecvd : %s\n", buffer);
            sleep(10);
        }
    }
}