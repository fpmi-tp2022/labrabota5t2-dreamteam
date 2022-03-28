#include "../UserRepository.h"
#include "../sqlite3.h"

static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	
	return 0;
}

int TryGetUserByLogin(User* out_user, char login[])
{
	return -1;
}

int AddUser(User* user)
{
	return -1;
}