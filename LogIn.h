#include "musicTop.h"
#include "Bazadedate.h"

class LogIn
{
	int valid;
	int client;
	char mesaj[100];
	utilizator currentUser;
	Bazadedate Users;
public:
	LogIn();
	void setClient(int identificator_client);
	bool Read();
	int Selectie();
	void Respond(char* result);
};