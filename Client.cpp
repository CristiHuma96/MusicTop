#include "Client.h"
#include "musicTop.h"
void Client::setPORT(char *port)
{
	PORT=atoi(port);
}
void Client::Socket()
{
	if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("Eroare la socket().\n");
      exit(1);
    }
}

void Client::Initialize(char *adresa)
{
	server.sin_family = AF_INET;
 	server.sin_addr.s_addr = inet_addr(adresa);
  	server.sin_port = htons (PORT);
}
void Client::Connect()
{
	if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
    {
      perror ("[client]Eroare la connect().\n");
      exit(2);
    }
}
bool Client::Citire(char message[100])
{
	if(read(sd,message,100)<0)
    {
      perror("[client]Eroare la write()");
      exit(3);
    }
}
bool Client::Scriere(char message[100])
{
	if (write (sd, message,100) <= 0)
    {
      perror ("[client]Eroare la write() spre server.\n");
      exit(4);
    }
}
int Client::getSD()
{
	return sd;
}