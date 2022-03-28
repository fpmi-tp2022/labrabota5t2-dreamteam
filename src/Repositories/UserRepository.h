#ifndef _USER_REPO_DREAM_TEAM_GUARD
#define _USER_REPO_DREAM_TEAM_GUARD

#include "../Models/Authorization/User.h"
#include <vector>

std::vector<User> TryGetUserByLogin(std::string login);
int AddUser(User* user);

#endif