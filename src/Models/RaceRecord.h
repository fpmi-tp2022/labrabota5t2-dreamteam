#ifndef _RACE_RECORD_DREAM_TEAM_GUARD
#define _RACE_RECORD_DREAM_TEAM_GUARD

#include "Jockey.h"
#include "Horse.h"
#include "Race.h"

struct RaceRecord
{
	int Id;
	int Result;

	//fk race
	int RaceId;
	Race* race = NULL;

	//fk Jockey
	int JockeyId;
	Jockey* jockey = NULL;

	//fk Horse
	int HorseId;
	Horse* horse = NULL;
};

#endif