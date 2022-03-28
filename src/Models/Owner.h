#ifndef _OWNER_DREAM_TEAM_GUARD
#define _OWNER_DREAM_TEAM_GUARD

#include <cstddef>

#include "./Authorization/User.h"

struct Owner
{
	int Id;
	char Name[NAME_LENGTH];
	int YearOfBirth;
	char Adress[ADRESS_LENGTH];

	//fk User
	int IdentityId;
	User* Identity = NULL;
};

#endif