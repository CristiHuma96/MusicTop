#include "musicTop.h"
#include "SignUp.h"
#include "LogIn.h"
class Client_Manager
{
private:
	int client;
	socklen_t length;
	class SignUp Inregistrare;
	class LogIn Logare;
public:
	bool Accept(struct sockaddr_in from,int sd);
	void Welcome(int PORT);
	int First_Step();
	void Finish_Client();
	void Citeste(char mesaj[100]);
	void Scrie(char mesaj[100]);
};