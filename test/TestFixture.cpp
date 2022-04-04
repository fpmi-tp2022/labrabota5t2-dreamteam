#include <stdio.h>
#include <fstream>
#include <gtest/gtest.h>
#include "Repositories/HorseRepository.h"
#include "DBManagment/ConnectionKeeper.h"
#include "DBManagment/sqlite3.h"

class RepositoriesTests :public ::testing::Test {
protected:
	void SetUp() override {
		
	}

	void TearDown() override {
		CloseConnection();
	}
};

TEST_F(RepositoriesTests, HorseRepository) {
	auto a = GetHorsesWon();
}