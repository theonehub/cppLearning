#include <iostream>
#include "tcpClient.h"
#include <unistd.h>

int main(int argc, char** argv)
{
    if (argc < 6)
    {
        cout << "Wrong Usage!!!" << endl;
        return -1;
    }

    string localIP = argv[1];
    int localPort = atoi(argv[2]);
    string srvIP = argv[3];
    int srvPort = atoi(argv[4]);
    string msg = argv[5];

    tcpClient *client = new tcpClient(localIP, localPort);
    int fd = client->connectSrv(srvIP, srvPort);
    if (-1 != fd)
    {
        cout << "sending data " << fd <<endl;
        sleep(10);
        client->sendData(fd, msg);
        sleep(100);
    }

}