#pragma once
#include "musicTop.h"
#include "sqlite3.h" 

class Bazadedate
{
	 sqlite3 *db;
	 sqlite3_stmt *res;
	 int rc;
	 int CurrentUserRight;
public:
	 bool Open();
	 char* Insert(char username[100],char parola[100]);
	 char* Select(char username[100],char parola[100]);
	 int GetRight();
    
};