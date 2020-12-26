#include <iostream>
#include "tcpServer.h"

int main(int argc, const char** argv)
{
    if (argc < 3)
    {
        cout << "wrong usage!!";
        return -1;
    }

    string host(argv[1]);
    int port = atoi(argv[2]);
    int queueCount = atoi(argv[3]);

    tcpServer *server = new tcpServer(host, port, queueCount);
    if(NULL != server) 
    {
        if (server->connect())
        {
            cout << "Connected!!!" << endl;
            server->readData();
        }
    }
}