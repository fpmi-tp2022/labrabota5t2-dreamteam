#ifndef _CONNECTION_KEEPER_DREAM_TEAM_GUARD
#define _CONNECTION_KEEPER_DREAM_TEAM_GUARD

#include "sqlite3.h"
#include <string>

int OpenConnection(const std::string& path);
sqlite3* GetConnection();
int CloseConnection();

#endif