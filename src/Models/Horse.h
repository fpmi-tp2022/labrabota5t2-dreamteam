#ifndef _HORSE_DREAM_TEAM_GUARD
#define _HORSE_DREAM_TEAM_GUARD

#include <cstddef>

#include "Owner.h"

struct Horse 
{
	int Id;
	std::string Nickname;
	int Age;
	double Experience;
	double Price;

	//fk Owner
	int OwnerId;
	Owner* owner = NULL;
};

#endif