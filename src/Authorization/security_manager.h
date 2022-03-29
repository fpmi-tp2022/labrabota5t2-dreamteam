#ifndef _SECURITY_MANAGER_DREAM_TEAM_GUARD
#define _SECURITY_MANAGER_DREAM_TEAM_GUARD
#include <string>
#include "../Models/Authorization/Role.h"
#include "../Types/result_codes.h"

Result CheckLoginCollision(const std::string& login);

Result VerifyCredentials(const std::string& login, const std::string& password);

Result RegisterNewUser(const std::string& login, const std::string& password, Role role);

#endif //_SECURITY_MANAGER_DREAM_TEAM_GUARD