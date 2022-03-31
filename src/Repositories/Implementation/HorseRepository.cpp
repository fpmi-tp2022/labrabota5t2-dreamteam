#include "../HorseRepository.h"
#include <vector>
#include "../../DBManagment/includes/sqlite3.h"
#include "../../DBManagment/includes/ConnectionKeeper.h"

static int callback(void* out_param, int argc, char** argv, char** azColName)
{
	std::vector<HorseResults>* out_horses_results = (std::vector<HorseResults>*)out_param;

	for (int i = 0; i < argc; i += 2)
	{
		HorseResults horses_res;
		if (strcmp(azColName[i], "HorseId") == 0)
		{
			horses_res.HorseId = strtol(argv[i], nullptr, 10);
		}
		if (strcmp(azColName[i + 1], "TimesWon") == 0)
		{
			horses_res.TimesWon = strtol(argv[i + 1], nullptr, 10);
		}
		out_horses_results->push_back(horses_res);
	}

	return 0;
}

std::vector<HorseResults> GetHorsesWon() 
{
	std::vector<HorseResults> results;

	std::string query = "SELECT rr.HorseId, Count(rr.Result) AS TimesWon FROM RaceRecord AS rr WHERE rr.Result = 1 GROUP BY rr.HorseId";

	sqlite3* db = GetConnection();

	char* zErrMsg = 0;

	int rc = sqlite3_exec(db, query.c_str(), callback, &results, &zErrMsg);

	return results;
}