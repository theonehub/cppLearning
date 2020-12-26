#include <iostream>
#include <string>

using namespace std;

class tcpServer
{
private:
    string mHost;
    int mPort;
    int mQueueCount;
    int mFd;

public:
    tcpServer(string& host, int port, int queueCount):mHost(host),mPort(port),mQueueCount(queueCount){};
    ~tcpServer();

    int getFd();

    bool connect();
    void readData();
};
