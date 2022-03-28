#ifndef _USER_DREAM_TEAM_GUARD
#define _USER_DREAM_TEAM_GUARD

#include "Role.h"
#include "../../Constants/Constants.h"
#include <string>

struct User 
{
	int Id;
	std::string Email;
	std::string PasswordSigned;
	Role Role;
};

#endif