#include "Client.h"

char msg[100];

int main (int argc, char *argv[])
{
  int verificat=0;
  Client A;		
  if (argc != 3)
  {
    printf ("Sintaxa: %s <adresa_server> <port>\n", argv[0]);
    return -1;
  }

  A.setPORT(argv[2]);
  A.Socket();
  A.Initialize(argv[1]);
  A.Connect();
  while(verificat==0)
  {
    A.Citire(msg);
    printf("[client]%s\n",msg);
  
    printf ("[client]Introduceti comanda dorita: ");
    fflush (stdout);
    scanf("%s",msg);
    while(strcmp(msg,"SIGNUP")!=0 && strcmp(msg,"LOGIN")!=0)
    {
      printf("Comanda invalida!\n[client]Va rugam alegeti alta comanda:");
      fflush(stdout);
      scanf("%s",msg);
    }
     A.Scriere(msg);

    utilizator currentUser;
    bzero(&currentUser,200);
    printf ("[client]Introduceti un username: ");
    fflush (stdout);
    scanf("%s",currentUser.username);
    printf ("[client]Introduceti o parola: ");
    fflush (stdout);
    scanf("%s",currentUser.parola);
    
    if (write (A.getSD(), &currentUser, sizeof(currentUser)) <= 0)
      {
        perror ("[client]Eroare la write().\n");
        return errno;
      }
    A.Citire(msg);
    printf ("[client]Mesajul primit este: %s\n\n", msg);
    if(strcmp(msg,"Succes!")==0)
      verificat=1;
  }
    close (A.getSD());
}
