#ifndef _OWNER_REPO_DREAM_TEAM_GUARD
#define _OWNER_REPO_DREAM_TEAM_GUARD

#include <vector>
#include "../Models/Horse.h"
#include "../Models/Owner.h"

std::vector<Horse> GetHorsesByOwnerId(int OwnerId);

Horse GetBestHorse(int OwnerId);

int Update(Owner owner);

Owner GetOwnerInfo(int ownerId);

#endif