#ifndef _OWNER_DREAM_TEAM_GUARD
#define _OWNER_DREAM_TEAM_GUARD

#include <cstddef>

#include "./Authorization/User.h"

struct Owner
{
	int Id;
	std::string Name;
	int YearOfBirth;
	std::string Address;

	//fk User
	int IdentityId;
	User* Identity = NULL;
};

#endif