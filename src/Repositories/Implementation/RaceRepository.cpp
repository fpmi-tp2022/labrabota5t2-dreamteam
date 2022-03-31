#include "../RaceRepository.h"
#include "../../DBManagment/includes/sqlite3.h"
#include "../../DBManagment/includes/ConnectionKeeper.h"
#include <string>

int AddRace(Race race)
{
	sqlite3* db = GetConnection();

	std::string query = "INSERT INTO Race (Date) VALUES ('";
	std::string query_appended = query.append(race.Date).append("')");

	char* zErrMsg = 0;

	int rc = sqlite3_exec(db, query_appended.c_str(), nullptr, 0, &zErrMsg);

	return rc;
}

int UpdateRace(Race race)
{
	sqlite3* db = GetConnection();

	std::string query = "UPDATE Race SET Date = '";
	std::string query_appended = query
		.append(race.Date)
		.append("' WHERE Race.Id = ")
		.append(std::to_string(race.Id));

	char* zErrMsg = 0;

	int rc = sqlite3_exec(db, query_appended.c_str(), nullptr, 0, &zErrMsg);

	return rc;
}