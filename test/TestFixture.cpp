#include <stdio.h>
#include <fstream>
#include <gtest/gtest.h>
#include "Repositories/HorseRepository.h"
#include "DBManagment/ConnectionKeeper.h"
#include "DBManagment/sqlite3.h"

class RepositoriesTests :public ::testing::Test {
protected:
	sqlite3* db;

	static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
		int i;
		for (i = 0; i < argc; i++) {
			printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		}
		printf("\n");
		return 0;
	}


	void SetUp() override {
		std::string sql, buff;
		std::ifstream myfile("test.sql");
		if (myfile.is_open())
		{
			while (getline(myfile, buff))
			{
				sql += buff;
			}
			myfile.close();
		}

		int rc = OpenConnection("test.db");
		db = GetConnection();
		char* zErrMsg = 0;
		rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
	}

	void TearDown() override {
		CloseConnection();
	}
};

TEST(govno, zhopa) {
	auto a = GetHorsesWon();
}