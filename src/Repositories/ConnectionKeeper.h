#ifndef _CONNECTION_KEEPER_DREAM_TEAM_GUARD
#define _CONNECTION_KEEPER_DREAM_TEAM_GUARD

#include "sqlite3.h"

sqlite3* db;

int OpenConnection();
sqlite3* GetConnection();
int CloseConnection();

#endif