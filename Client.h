#include "musicTop.h"
class Client
{
private:
	int PORT,sd;
  	struct sockaddr_in server;	
  	char mesaj[100];
public:
	void setPORT(char *port);
	void Socket();
	void Initialize(char *server);
	void Connect();
	bool Citire(char message[100]);
	bool Scriere(char message[100]);
	int getSD();
};