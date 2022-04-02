#ifndef _PRIZE_DREAM_TEAM_GUARD
#define _PRIZE_DREAM_TEAM_GUARD

#include "RaceRecord.h"

struct Prize
{
	int Id;
	double Prize;

	//fk RaceRecord
	int RaceRecordId;
};

#endif