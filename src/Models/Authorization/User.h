#ifndef _USER_DREAM_TEAM_GUARD
#define _USER_DREAM_TEAM_GUARD

#include "Role.h"
#include "../../Constants/Constants.h"

struct User 
{
	int Id;
	char Email[EMAIL_LENGTH];
	char PasswordSigned[PASSWORD_SIGNED_LENGTH];
	Role Role;
};

#endif