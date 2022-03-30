#include "../OwnerRepository.h"
#include "../../DBManagment/includes/sqlite3.h"
#include "../../DBManagment/includes/ConnectionKeeper.h"
#include <string>

static int callback(void* out_param, int argc, char** argv, char** azColName)
{
	std::vector<Horse>* out_horses = (std::vector<Horse>*)out_param;

	for (int i = 0; i < argc; i += 10)
	{
		Horse horse;
		if (strcmp(azColName[i], "Id") == 0)
		{
			horse.Id = strtol(argv[i], nullptr, 10);
		}
		if (strcmp(azColName[i + 1], "Nickname") == 0)
		{
			horse.Nickname = std::string(argv[i + 1]);
		}
		if (strcmp(azColName[i + 2], "Age") == 0)
		{
			horse.Age = strtol(argv[i + 2], nullptr, 10);
		}
		if (strcmp(azColName[i + 3], "Experience") == 0)
		{
			horse.Experience = strtod(argv[i + 3], nullptr);
		}

		if (strcmp(azColName[i + 4], "Price") == 0)
		{
			horse.Price = strtod(argv[i + 4], nullptr);
		}
		if (strcmp(azColName[i + 5], "OwnerId") == 0)
		{
			horse.OwnerId = strtol(argv[i + 5], nullptr, 10);
			horse.Owner = new Owner;
			horse.Owner->Id = horse.OwnerId;
		}
		if (strcmp(azColName[i + 6], "Name") == 0)
		{
			horse.Owner->Name= std::string(argv[i + 6]);
		}
		if (strcmp(azColName[i + 7], "YearOfBirth") == 0)
		{
			horse.Owner->YearOfBirth = strtod(argv[i + 7], nullptr);
		}

		if (strcmp(azColName[i + 8], "Address") == 0)
		{
			horse.Owner->Address = std::string(argv[i + 8]);
		}

		if (strcmp(azColName[i + 9], "IdentityId") == 0)
		{
			horse.Owner->IdentityId = strtod(argv[i + 9], nullptr);
		}
		out_horses->push_back(horse);
	}

	return 0;
}

std::vector<Horse> GetHorsesByOwnerId(int OwnerId) 
{
	std::vector<Horse> horses;
	std::string query = "SELECT \
						 h.Id, \
						 h.Nickname, \
						 h.Age, \
						 h.Experience, \
						 h.Price, \
						 h.OwnerId, \
						 o.Name, \
						 o.YearOfBirth, \
						 o.Address, \
						 o.IdentityId \
						 FROM Horse AS h \
							JOIN Owner AS o ON h.OwnerId = o.Id \
							WHERE o.Id = ";

	std::string query_appended = query.append(std::to_string(OwnerId));

	sqlite3* db = GetConnection();

	char* zErrMsg = 0;

	int rc = sqlite3_exec(db, query_appended.c_str(), callback, &horses, &zErrMsg);

	return horses;
}

Horce GetBestHorce(int OwnerId) {
	auto horces = GetHorsesByOwnerId(OwnerId);
	Horse answer = horces[0];

	for(auto h : horces)
	{
		if (h.Experience > answer.Experience) {
			answer = h;
		}
	}

	return answer;
}