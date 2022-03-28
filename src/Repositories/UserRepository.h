#ifndef _USER_REPO_DREAM_TEAM_GUARD
#define _USER_REPO_DREAM_TEAM_GUARD

#include "../Models/Authorization/User.h"

int TryGetUserByLogin(User* out_user, char login[]);
int AddUser(User* user);

#endif