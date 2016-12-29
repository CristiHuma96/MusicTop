#include "SignUp.h"
SignUp::SignUp()
{
	valid=0;
	bzero (&currentUser,200);
	bzero(mesaj,100);
}
void SignUp::setClient(int identificator_client)
{
	client=identificator_client;
}
bool SignUp::Read()
{
	if(read(client,&currentUser,sizeof(currentUser))<0)
    	return false;
  	else
  		return true;
}
int SignUp::Inserare()
{
	char * result;
	bool check=Users.Open();
	while(check==false)
		check=Users.Open();
	result=Users.Insert(currentUser.username,currentUser.parola);
	return Respond(result);
    
}
int SignUp::Respond(char* raspuns)
{
	if(raspuns==NULL)
	{
		strcpy(mesaj,"Succes!");
		if(write(client,mesaj,100)<0)
  		{	
    		printf("[server]Eroare la write()\n");
    		return false;
  		}
		valid=1;
	}
	else
	{
		strcpy(mesaj,"Esec!");
		if(write(client,mesaj,100)<0)
  		{
    		printf("[server]Eroare la write()\n");
    		return false;
  		}
  		valid=0;
	}
  	return valid;
 }
