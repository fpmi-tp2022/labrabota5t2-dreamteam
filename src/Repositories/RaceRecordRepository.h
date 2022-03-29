#ifndef _RACE_RECORD_REPOSITORY_DREAM_TEAM_GUARD
#define _RACE_RECORD_REPOSITORY_DREAM_TEAM_GUARD

#include "../Models/RaceRecord.h"
#include <vector>

std::vector<RaceRecord> GetBestHorseRecords();

std::vector<RaceRecord> GetJockeyRecords();

std::vector<RaceRecord> GetOwnerRecords();

std::vector<RaceRecord> GetAllRecordsInPeriod(std::string from, std::string to);

#endif