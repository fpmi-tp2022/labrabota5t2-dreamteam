#include <stdio.h>
#include <fstream>
#include <gtest/gtest.h>
#include "Repositories/HorseRepository.h"
#include "DBManagment/ConnectionKeeper.h"
#include "DBManagment/sqlite3.h"
#include "executor.h"
#include <filesystem>

static const std::string db_path = "../../test/test.db";
static const std::string temp_db_path = "./temp_test.db";

class RepositoriesTests :public ::testing::Test {
protected:
	void SetUp() override {
		ASSERT_TRUE(std::filesystem::exists(db_path)) << "Can't find test db: " << db_path ;

		std::filesystem::remove(temp_db_path);
		std::filesystem::copy(db_path, temp_db_path);
		ASSERT_EQ(0, OpenConnection(temp_db_path));
	}

	void TearDown() override {
		CloseConnection();
		std::filesystem::remove(temp_db_path);
	}

	static int callback_exec(void* data, int columns_num, char** text, char** column_name) {
		std::string* output = (std::string*)data;

		for (int i = 0; i < columns_num; i++) {
			output->append(text[i] ? text[i] : "NULL");
			output->append(" ");
		}
		output->append("\n");
		return 0;
	}

	std::string ExecuteSQL(const std::string& query) {
		std::string output;
		int rc = sqlite3_exec(GetConnection(), query.c_str(), callback_exec, &output, NULL);

		if (rc != SQLITE_OK) {
			printf("An error occured: %s.\n", sqlite3_errmsg(GetConnection()));
			return "";
		}
		return output;
	}

private: 
	
};

TEST_F(RepositoriesTests, HorseRepository) {
	auto horse = GetHorse(2);
	auto nickname = ExecuteSQL("SELECT Nickname from Horse WHERE Id=2");
	nickname = nickname.substr(0, nickname.find(" "));
	ASSERT_STREQ(nickname.c_str(), horse.Nickname.c_str());
}