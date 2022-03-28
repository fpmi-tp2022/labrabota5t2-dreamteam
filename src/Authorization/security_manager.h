#ifndef _SECURITY_MANAGER_DREAM_TEAM_GUARD
#define _SECURITY_MANAGER_DREAM_TEAM_GUARD
#include <string>

bool CheckLoginCollision(const std::string& login);

int VerifyCredentials(const std::string& login, const std::string& password);

#endif //_SECURITY_MANAGER_DREAM_TEAM_GUARD