#include <string.h>

#include "../UserRepository.h"
#include "../../DBManagment/includes/sqlite3.h"
#include "../../DBManagment/includes/ConnectionKeeper.h"
#include <stdlib.h>
#include <string>

static int callback(void* out_param, int argc, char** argv, char** azColName) 
{
	User* out_user = (User*)out_param;
	for (int i = 0; i < argc; i++) 
	{
		if (strcmp(azColName[i], "Id") == 0) 
		{
			out_user->Id = strtol(argv[i], nullptr, 10);
		}
		else if (strcmp(azColName[i], "Email") == 0) 
		{
			out_user->Email = std::string(argv[i]);
		}
		else if (strcmp(azColName[i], "PasswordSigned") == 0)
		{
			out_user->PasswordSigned = std::string(argv[i]);
		}
		else if (strcmp(azColName[i], "Role") == 0)
		{
			out_user->Role = (Role)strtol(argv[i], nullptr, 10);
		}
	}
	
	return 0;
}

int TryGetUserByLogin(User* out_user, std::string login)
{
	sqlite3* db = GetConnection();
	char* zErrMsg = 0;
	std::string query_string = "SELECT * FROM User WHERE User.Email = '";
	const char* query = query_string.append(login).append("'").c_str();
	int rc = sqlite3_exec(db, query, callback, out_user, &zErrMsg);
	printf("%s", zErrMsg);
	return -1;
}

int AddUser(User* user)
{
	return -1;
}