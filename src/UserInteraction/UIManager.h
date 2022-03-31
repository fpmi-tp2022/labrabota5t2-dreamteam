#ifndef _UIMANAGER_DREAM_TEAM_GUARD
#define _UIMANAGER_DREAM_TEAM_GUARD

#include "../Models/Authorization/User.h"
#include "../Models/RaceRecord.h"
#include "../Models/Jockey.h"
#include "../Models/Horse.h"

class UIManager
{
public:
	UIManager(User user);
	~UIManager();
	bool ShowMenu();

private:
	User user;
	void SelectForJockey();
	void SelectForOwner();
	void SelectForAdmin();
	void PrintInfoAboutBestJockey();
	void PrintInfoAboutAllRaces();
	void PrintHorseInfo(Horse horce);
	void PrintJockeyInfo(Jockey jockey, bool nextline);
	void PrintRaceInfo(RaceRecord race);
};

#endif