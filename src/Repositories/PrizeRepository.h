#ifndef _PRIZE_REPO_DREAM_TEAM_GUARD
#define _PRIZE_REPO_DREAM_TEAM_GUARD

#include <vector>
#include "../Models/Prize.h"

int GivePrize(double money, int raceId);
std::vector<Prize> GetAll();

#endif