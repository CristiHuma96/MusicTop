#include "musicTop.h"
class Connection
{
private:
	int sd,MAX_CUSTOMERS,PORT;
	struct sockaddr_in server;
	struct sockaddr_in from;
public:
	Connection();
	void Socket();
	void Initialize();
	void Bind();
	void Listen();

	int getSd();
	sockaddr_in getSockfd();
	int getPORT();
};
