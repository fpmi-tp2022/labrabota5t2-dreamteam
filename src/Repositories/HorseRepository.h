#ifndef _HORSE_REPO_DREAM_TEAM_GUARD
#define _HORSE_REPO_DREAM_TEAM_GUARD

#include "../Models/Horse.h"
#include <vector>

struct HorseResults {
	int HorseId;
	int TimesWon;
};

std::vector<HorseResults> GetHorsesWon();

int Add(Horse horse);

int Update(Horse horse);

int DeleteHorse(int horseId);

#endif