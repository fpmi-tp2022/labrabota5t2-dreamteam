#ifndef _JOCKEY_DREAM_TEAM_GUARD
#define _JOCKEY_DREAM_TEAM_GUARD

#include <cstddef>

#include "../Constants/Constants.h"
#include "./Authorization/User.h"

struct Jockey 
{
	int Id;
	std::string Name;
	double Experience;
	int YearOfBirth;
	std::string Address;

	//fk User
	int IdentityId;
	User* Identity = NULL;
};

#endif