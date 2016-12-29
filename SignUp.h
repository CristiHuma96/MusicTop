#include "musicTop.h"
#include "Bazadedate.h"
class SignUp
{
private:
	int valid;
	int client;
	char mesaj[100];
	utilizator currentUser;
	Bazadedate Users;
public:
	SignUp();
	void setClient(int identificator_client);
	bool Read();
	int Inserare();
	int Respond(char* raspuns);
};