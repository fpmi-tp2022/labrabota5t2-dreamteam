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

static int callback_count(void* out_param, int argc, char** argv, char** azColName)
{
	int* out_count = (int*)out_param;

	for (int i = 0; i < argc; i += 1)
	{
		if (strcmp(azColName[i], "Count") == 0)
		{
			*out_count = (int)strtol(argv[i], nullptr, 10);
		}
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

int Add(Horse horse)
{
	char* zErrMsg = 0;

	int isPresent = 0;

	std::string query = "SELECT Count(Owner.Id) AS Count FROM Owner WHERE Owner.Id = ";

	sqlite3* db = GetConnection();

	int rc1 = sqlite3_exec(db, query.append(std::to_string(horse.OwnerId)).c_str(), callback_count, &isPresent, &zErrMsg);

	if (isPresent == 0) 
	{
		return -1;
	}

	std::string command = "INSERT INTO Horse (Nickname, Age, Experience, Price, OwnerId) VALUES ('";

	std::string appended_query = command
		.append(horse.Nickname)
		.append("', ")
		.append(std::to_string(horse.Age))
		.append(", ")
		.append(std::to_string(horse.Experience))
		.append(", ")
		.append(std::to_string(horse.Price))
		.append(", ")
		.append(std::to_string(horse.OwnerId))
		.append(")");

	int rc = sqlite3_exec(db, appended_query.c_str(), nullptr, 0, &zErrMsg);
	return rc;
}

int Update(Horse horse)
{
	char* zErrMsg = 0;

	int isPresent = 0;

	std::string query = "SELECT Count(Owner.Id) AS Count FROM Owner WHERE Owner.Id = ";

	sqlite3* db = GetConnection();

	int rc1 = sqlite3_exec(db, query.append(std::to_string(horse.OwnerId)).c_str(), callback_count, &isPresent, &zErrMsg);

	if (isPresent == 0)
	{
		return -1;
	}

	std::string query2 = "UPDATE Horse SET Nickname = '";

	std::string appended_query = query2
		.append(horse.Nickname)
		.append("', Age = ")
		.append(std::to_string(horse.Age))
		.append(", Price =")
		.append(std::to_string(horse.Price))
		.append(", OwnerId = ")
		.append(std::to_string(horse.OwnerId))
		.append(" WHERE Id = ")
		.append(std::to_string(horse.Id));

	int rc = sqlite3_exec(db, appended_query.c_str(), nullptr, 0, &zErrMsg);
	return rc;
}