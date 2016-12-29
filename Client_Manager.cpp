#include "Client_Manager.h"
#include "musicTop.h"
#define ERR_ACCEPT

bool Client_Manager::Accept(struct sockaddr_in from,int sd)
{
  length=sizeof(from);
	client = accept (sd, (struct sockaddr *) &from, &length);
	if (client < 0)
  {
        perror ("[server]Eroare la accept().\n");
        return false;
  }
  return true;
}

void Client_Manager::Welcome(int PORT)
{
    printf ("\n[server]Asteptam la portul %d...\n",PORT);
    fflush (stdout);
}

int Client_Manager::First_Step()
{
	int verificat=0;
	char mesaj[100];
	bzero (mesaj, 100);
  while(verificat==0)
  {
    printf ("[server]Asteptam comanda...\n");
    fflush (stdout);
    strcpy(mesaj,"Comenzile disponibile sunt: LOGIN/SIGNUP");
    Scrie(mesaj);
    strcpy(mesaj,"[server]Comunicare finalizata!\n");
    Citeste(mesaj);
    printf("[server]Mesajul receptionat este %s\n",mesaj);
    fflush(stdout);
    if(strcmp(mesaj,"LOGIN")==0)
    {
      Logare.setClient(client);
      while(Logare.Read()==false)
           perror("[server]Eroare la read()\n");
      verificat=Logare.Selectie();
    }
    if(strcmp(mesaj,"SIGNUP")==0)
    {
      Inregistrare.setClient(client);
      while(Inregistrare.Read()==false)
           perror("[server]Eroare la read()\n");
      verificat=Inregistrare.Inserare();
    }
  }

  /*verificat=1 <=> client obisnuit */
  /*verificat=2 <=> administrator */
  //Oferire_servicii(client,verificat);

  printf("[server]Comunicare finalizata!");
  fflush(stdout);
  return verificat;
}

void Client_Manager::Finish_Client()
{
 	close(client);
}

void Client_Manager::Scrie(char mesaj[100])
{
  if(write(client,mesaj,100)<0)
      printf("[server]Eroare la write()!\n");
}

void Client_Manager::Citeste(char mesaj[100])
{
  if(read(client,mesaj,100)<0)
      printf("[server]Eroare la citire()!\n");
}
