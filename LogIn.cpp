#include "LogIn.h"
LogIn::LogIn()
{
	valid=0;
	bzero (&currentUser,200);
	bzero(mesaj,100);
}
void LogIn::setClient(int identificator_client)
{
	client=identificator_client;
}
bool LogIn::Read()
{
	if(read(client,&currentUser,sizeof(currentUser))<0)
    	return false;
  	else
  		return true;
}
int LogIn::Selectie()
{
	char * result;
	bool check=Users.Open();
	while(check==false)
		check=Users.Open();
	result=Users.Select(currentUser.username,currentUser.parola);
	Respond(result);
	return Users.GetRight();
}
void LogIn::Respond(char * raspuns)
{
	if(raspuns==NULL)
	{
		strcpy(mesaj,"Succes!");
		if(write(client,mesaj,100)<0)
    		printf("[server]Eroare la write()\n");
	}
	else
	{
		strcpy(mesaj,"Esec!");
		if(write(client,mesaj,100)<0)
    		printf("[server]Eroare la write()\n");
	}
}