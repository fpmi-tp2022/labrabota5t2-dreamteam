#include "../RaceRecordRepository.h"
#include "../../DBManagment/includes/sqlite3.h"
#include "../../DBManagment/includes/ConnectionKeeper.h"

static int callback_RaceRecords(void* out_param, int argc, char** argv, char** azColName)
{
	std::vector<RaceRecord>* out_vector = (std::vector<RaceRecord>*)out_param;

	for (int i = 0; i < argc; i += 21)
	{
		RaceRecord rr;
		if (strcmp(azColName[i], "Id") == 0)
		{
			rr.Id = strtol(argv[i], nullptr, 10);
		}
		if (strcmp(azColName[i + 1], "Result") == 0)
		{
			rr.Result = strtol(argv[i + 1], nullptr, 10);
		}
		if (strcmp(azColName[i + 2], "RaceId") == 0)
		{
			rr.RaceId = strtol(argv[i + 2], nullptr, 10);
		}
		if (strcmp(azColName[i + 3], "JockeyId") == 0)
		{
			rr.JockeyId = strtol(argv[i + 3], nullptr, 10);
		}
		if (strcmp(azColName[i + 4], "HorseId") == 0)
		{
			rr.Horse = new Horse;
			rr.HorseId = strtol(argv[i + 4], nullptr, 10);
			rr.Horse->Id = rr.HorseId;
		}
		if (strcmp(azColName[i + 5], "Date") == 0)
		{
			rr.Race = new Race;
			rr.Race->Id = rr.RaceId;
			rr.Race->Date = std::string(argv[i + 5]);
		}
		if (strcmp(azColName[i + 6], "Name") == 0)
		{
			rr.Jockey = new Jockey;
			rr.Jockey->Name = std::string(argv[i + 6]);
		}
		if (strcmp(azColName[i + 7], "Experience") == 0)
		{
			rr.Jockey->Experience = strtod(argv[i + 7], nullptr);
		}
		if (strcmp(azColName[i + 8], "YearOfBirth") == 0)
		{
			rr.Jockey->YearOfBirth = strtol(argv[i + 8], nullptr, 10);
		}
		if (strcmp(azColName[i + 9], "Address") == 0)
		{
			rr.Jockey->Address = std::string(argv[i + 9]);
		}
		if (strcmp(azColName[i + 10], "IdentityId") == 0)
		{
			rr.Jockey->IdentityId = strtol(argv[i + 10], nullptr, 10);
			rr.Jockey->Identity = nullptr;
		}
		if (strcmp(azColName[i + 11], "Id") == 0)
		{
			rr.Jockey->Id = strtol(argv[i + 11], nullptr, 10);
			rr.JockeyId = rr.Jockey->Id;
		}
		if (strcmp(azColName[i + 12], "Nickname") == 0)
		{
			rr.Horse->Nickname = std::string(argv[i + 12]);
		}
		if (strcmp(azColName[i + 13], "Age") == 0)
		{
			rr.Horse->Age = strtol(argv[i + 13], nullptr, 10);
		}
		if (strcmp(azColName[i + 14], "Experience") == 0)
		{
			rr.Horse->Experience = strtod(argv[i + 14], nullptr);
		}
		if (strcmp(azColName[i + 15], "Price") == 0)
		{
			rr.Horse->Price = strtod(argv[i + 15], nullptr);
		}

		if (strcmp(azColName[i + 16], "Id") == 0)
		{
			rr.Horse->Owner = new Owner;
			rr.Horse->Owner->Id = strtod(argv[i + 16], nullptr);
			rr.Horse->OwnerId = rr.Horse->Owner->Id;
		}

		if (strcmp(azColName[i + 17], "Name") == 0)
		{
			rr.Horse->Owner->Name = std::string(argv[i + 17]);
		}

		if (strcmp(azColName[i + 18], "YearOfBirth") == 0)
		{
			rr.Horse->Owner->YearOfBirth = strtol(argv[i + 18], nullptr, 10);
		}

		if (strcmp(azColName[i + 19], "Address") == 0)
		{
			rr.Horse->Owner->Address = std::string(argv[i + 19]);
		}

		if (strcmp(azColName[i + 20], "IdentityId") == 0)
		{
			rr.Horse->Owner->IdentityId = strtol(argv[i + 20], nullptr, 10);
		}

		out_vector->push_back(rr);
	}

	return 0;	
}

std::string AllIncludedQuery() 
{
	return "SELECT \
				rr.Id, \
				rr.Result, \
				rr.RaceId, \
				rr.JockeyId, \
				rr.HorseId, \
				r.Date, \
				j.Name, \
				j.Experience, \
				j.YearOfBirth, \
				j.Address, \
				j.IdentityId, \
				j.Id, \
				h.Nickname, \
				h.Age, \
				h.Experience, \
				h.Price, \
				o.Id, \
				o.Name, \
				o.YearOfBirth, \
				o.Address, \
				o.IdentityId\
			FROM \
				RaceRecord AS rr \
					JOIN Race AS r ON rr.RaceId = r.Id \
					JOIN Horse AS h ON rr.HorseId = h.Id \
					JOIN Jockey AS j ON rr.JockeyId = j.Id \
					JOIN Owner AS o ON h.OwnerId = o.Id ";

}

std::vector<RaceRecord> GetJockeyRecords(int JockeyId)
{
	std::vector<RaceRecord> records;

	sqlite3* db = GetConnection();

	char* zErrMsg = 0;

	std::string query_string_appended = AllIncludedQuery().append("WHERE rr.JockeyId = ").append(std::to_string(JockeyId));

	int rc = sqlite3_exec(db, query_string_appended.c_str(), callback_RaceRecords, &records, &zErrMsg);

	return records;
}

std::vector<RaceRecord> GetByHorseId(int horseId)
{
	std::vector<RaceRecord> records;

	sqlite3* db = GetConnection();

	char* zErrMsg = 0;

	std::string query_string_appended = AllIncludedQuery().append("WHERE h.Id = ").append(std::to_string(horseId));

	int rc = sqlite3_exec(db, query_string_appended.c_str(), callback_RaceRecords, &records, &zErrMsg);

	return records;
}

std::vector<RaceRecord> GetByPeriod(std::string from, std::string to)
{
	std::vector<RaceRecord> records;

	sqlite3* db = GetConnection();

	char* zErrMsg = 0;

	std::string query_string_appended = AllIncludedQuery().append("WHERE r.Date > '").append(from).append("' AND r.Date < '").append(to).append("'");

	int rc = sqlite3_exec(db, query_string_appended.c_str(), callback_RaceRecords, &records, &zErrMsg);

	return records;
}