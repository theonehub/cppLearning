#include <iostream>

using namespace std;

class tcpClient
{
private:
    string mServerIP;
    int mServerPort;
    string mLocalIP;
    int mLocalPort;
    int mFd;

public:
    tcpClient(string& localIP, int localport):mLocalIP(localIP), mLocalPort(localport){};
    ~tcpClient();
    int connectSrv(string& serverIP, int serverPort);
    int sendData(int fd, string& data);
};

