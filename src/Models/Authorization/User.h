#ifndef _USER_DREAM_TEAM_GUARD
#define _USER_DREAM_TEAM_GUARD

#include "Role.h"
#include <string>

struct User 
{
	int Id;
	std::string Email;
	std::string PasswordSigned;
	Role role;
};

#endif