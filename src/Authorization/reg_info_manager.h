#ifndef _REG_INFO_MANAGER_DREAM_TEAM_GUARD
#define _REG_INFO_MANAGER_TEAM_GUARD
#include "../Types/types.h"
#include <string>

Result RegisterJockey(std::string name, int yearOfBirth, std::string address, int user_id);

Result RegisterOwner(std::string name, int yearOfBirth, std::string address, int user_id);

#endif //_REG_INFO_MANAGER_TEAM_GUARD