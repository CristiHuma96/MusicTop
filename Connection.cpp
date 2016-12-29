#include "Connection.h"
Connection::Connection()
{
    PORT=6789;
    MAX_CUSTOMERS=30;
}
void Connection::Socket()
{
	if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("[server]Eroare la socket().\n");
      exit(1);
    }
}

void Connection::Initialize()
{
  bzero (&server, sizeof (server));
  bzero (&from, sizeof (from));

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = htonl (INADDR_ANY);
  server.sin_port = htons (PORT);
}

void Connection::Bind()
{
	if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)
    {
      perror ("[server]Eroare la bind().\n");
      exit(2);
    }
}
void Connection::Listen()
{
	if (listen (sd, MAX_CUSTOMERS) == -1)
    {
      perror ("[server]Eroare la listen().\n");
      exit(3);
    }
}
int Connection::getSd()
{
	return sd;
}
sockaddr_in Connection::getSockfd()
{
	return from;
}
int Connection::getPORT()
{
    return PORT;
}
