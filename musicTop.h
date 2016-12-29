#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
int errno;

class utilizator
{
public:
  char username[100];
  char parola[100];
};


int LogIn(int client);
int SignUp(int client);
int Inregistrare(char username[100],char password[100]);
void Oferire_servicii(int client,int tip_client);
void Serviciu1(int client,int tip_client);
void Serviciu2(int client,int tip_client);
void Serviciu3(int client,int tip_client);
void Serviciu4(int client,int tip_client);
void Serviciu5(int client,int tip_client);
void Serviciu6(int client,int tip_client);
void RemoveSong(int client);
void RemoveRight(int client);
void Help();
int checkValid(char sample[100]);
int checkRegistered(char username[100],char password[100]);

