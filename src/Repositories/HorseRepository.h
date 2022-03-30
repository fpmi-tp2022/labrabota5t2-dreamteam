#ifndef _HORSE_REPO_DREAM_TEAM_GUARD
#define _HORSE_REPO_DREAM_TEAM_GUARD

#include "../Models/Horse.h"
#include <vector>

struct HorseResults {
	int HorseId;
	int TimesWon;
};

//TODO
std::vector<HorseResults> GetHorsesWon();

#endif