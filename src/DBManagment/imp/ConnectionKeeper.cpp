#include "../ConnectionKeeper.h"
#include "../sqlite3.h"
#include <stdio.h>
sqlite3* db;

int OpenConnection() 
{
	int rc = sqlite3_open("../../hippodrome.db", &db);
	return rc;
}

sqlite3* GetConnection() 
{
	return db;
}

int CloseConnection() 
{
	return sqlite3_close(db);;
}