
#include "Connection.h"
#include "Client_Manager.h"
int main()
{	
	pid_t pid;
	int user_type=0;
	Connection conexiune;
	conexiune.Socket();
	conexiune.Initialize();
	conexiune.Bind();
	conexiune.Listen();
	while(1)
	{
		Client_Manager Manager;
		Manager.Welcome(conexiune.getPORT());
		if(Manager.Accept(conexiune.getSockfd(),conexiune.getSd())==false)
			continue;
		pid=fork();
		if(pid==0)
		{
			user_type=Manager.First_Step();
			Manager.Finish_Client();
		}
		if(pid==-1)
      	{
        	perror("[server]Eroare la fork().\n");
        	exit(0);
      	}
      	else
      		Manager.Finish_Client();
	}
	return 0;
}
