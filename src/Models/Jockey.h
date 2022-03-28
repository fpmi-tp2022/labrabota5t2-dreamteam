#ifndef _JOCKEY_DREAM_TEAM_GUARD
#define _JOCKEY_DREAM_TEAM_GUARD

#include <cstddef>

#include "../Constants/Constants.h"
#include "./Authorization/User.h"

struct Jockey 
{
	int Id;
	char Name[NAME_LENGTH];
	double Experience;
	int YearOfBirth;
	char Adress[ADRESS_LENGTH];

	//fk User
	int IdentityId;
	User* Identity = NULL;
};

#endif