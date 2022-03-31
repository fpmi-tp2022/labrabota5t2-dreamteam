#ifndef _JOCKEY_REPO_DREAM_TEAM_GUARD
#define _JOCKEY_REPO_DREAM_TEAM_GUARD

#include "../Models/Jockey.h"
#include <vector>

struct JockeyExperince 
{
	int JockeyId;
	int RaceAmount;
};

std::vector<JockeyExperince> GetJockeyExperience();

JockeyExperince GetBestJockey();

Jockey GetJockeyInfo(int jockeyId);

#endif