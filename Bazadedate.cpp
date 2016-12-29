#include "Bazadedate.h"

int callback(void *NotUsed, int argc, char **argv, char **azColName);
int drept=0;
bool Bazadedate::Open()
{
	rc = sqlite3_open("musicTop.db", &db);
	if( rc )
      return false;
   else
      printf("[server]Baza de date s-a deschis cu succes!\n");
      return true;
}
char* Bazadedate::Insert(char username[100],char parola[100])
{
  char sql[300];
  char *err_msg;
  strcpy(sql,"Insert into utilizatori values('");
  strcat(sql,username);
  strcat(sql,"', '");
  strcat(sql,parola);
  strcat(sql,"', ");
  strcat(sql,"1);");
  rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
  if (rc != SQLITE_OK ) 
  {
      printf("[server]Eroarea este %s\n",err_msg);
      sqlite3_close(db);
      return err_msg;
  } 
  printf("[server]Inregistrare cu succes!\n");
  sqlite3_close(db);
  return err_msg;
}
char* Bazadedate::Select(char username[100],char parola[100])
{
  char sql[300];
  char *err_msg;
  strcpy(sql,"Select right from utilizatori where username='");
  strcat(sql,username);
  strcat(sql,"' and parola='");
  strcat(sql,parola);
  strcat(sql,"';");
  printf("[server]Username=%s si parola=%s\n",username,parola);
  rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
  CurrentUserRight=drept;
  drept=0;
  if (rc != SQLITE_OK) 
  {
      printf("[server]Eroarea este %s\n",err_msg);
      sqlite3_close(db);
      return err_msg;
  }
  if(CurrentUserRight==0)
  {
      err_msg= (char*)malloc(strlen("Utilizator inexistent!\n") + 1);
      strcpy(err_msg,"Utilizator inexistent!\n");
      printf("[server]Eroarea este %s\n",err_msg);
      sqlite3_close(db);
      return err_msg;
  }
  printf("[server]Log in cu succes!\n");
  sqlite3_close(db);
  return err_msg;
}
int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    drept=atoi(argv[0]);
    return 0;
}
int Bazadedate::GetRight()
{
  return CurrentUserRight;
}