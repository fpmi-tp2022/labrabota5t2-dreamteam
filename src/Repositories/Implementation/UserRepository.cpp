#include <string.h>

#include "../UserRepository.h"
#include "../../DBManagment/includes/sqlite3.h"
#include "../../DBManagment/includes/ConnectionKeeper.h"
#include <stdlib.h>
#include <string>

static int callback(void* out_param, int argc, char** argv, char** azColName) 
{
	std::vector<User>* out_user = (std::vector<User>*)out_param;
	
	for (int i = 0; i < argc; i+=4) 
	{
		User user;
		if (strcmp(azColName[i], "Id") == 0) 
		{
			user.Id = strtol(argv[i], nullptr, 10);
		}
		if (strcmp(azColName[i + 1], "Email") == 0) 
		{
			user.Email = std::string(argv[i + 1]);
		}
		if (strcmp(azColName[i + 2], "PasswordSigned") == 0)
		{
			user.PasswordSigned = std::string(argv[i + 2]);
		}
		if (strcmp(azColName[i + 3], "Role") == 0)
		{
			user.Role = (Role)strtol(argv[i + 3], nullptr, 10);
		}
		out_user->push_back(user);
	}
	
	return 0;
}

std::vector<User> TryGetUserByLogin(std::string login)
{
	std::vector<User> vectorOfUsers;
	sqlite3* db = GetConnection();
	char* zErrMsg = 0;
	std::string query_string = "SELECT * FROM User WHERE User.Email = '";
	const char* query = query_string.append(login).append("'").c_str();
	int rc = sqlite3_exec(db, query, callback, &vectorOfUsers, &zErrMsg);
	printf("%s", zErrMsg);
	return vectorOfUsers;
}

int AddUser(User* user)
{
	sqlite3* db = GetConnection();
	char* zErrMsg = 0;
	std::string query_string = "INSERT INTO User (Email, PasswordSigned, Role) VALUES ('";
	const char* query = query_string.append(user->Email).append("','").append(user->PasswordSigned).append("',").append(std::to_string(user->Role)).append(")").c_str();
	int rc = sqlite3_exec(db, query, nullptr, 0, &zErrMsg);
	printf("%s", zErrMsg);
	return -1;
}