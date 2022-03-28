#ifndef _RACE_DREAM_TEAM_GUARD
#define _RACE_DREAM_TEAM_GUARD

#include "Jockey.h"
#include "Horse.h"

struct Race 
{
	int Id;
	char* Date;
	int Result;

	//fk Jockey
	int JockeyId;
	Jockey* Jockey = NULL;

	//fk Horse
	int HorseId;
	Horse* Horse = NULL;
};

#endif