#ifndef _RACE_RECORD_REPOSITORY_DREAM_TEAM_GUARD
#define _RACE_RECORD_REPOSITORY_DREAM_TEAM_GUARD

#include "../Models/RaceRecord.h"
#include <vector>

std::vector<RaceRecord> GetJockeyRecords(int jockeyId);

std::vector<RaceRecord> GetByHorseId(int horseId);

std::vector<RaceRecord> GetByPeriod(std::string from, std::string to);

//TODO
std::vector<RaceRecord> GetAllRaceRecords();

#endif