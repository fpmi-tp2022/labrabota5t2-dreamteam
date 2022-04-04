#include <stdio.h>
#include <fstream>
#include <gtest/gtest.h>
#include "Repositories/HorseRepository.h"
#include "Repositories/JockeyRepository.h"
#include "Repositories/OwnerRepository.h"
#include "Repositories/PrizeRepository.h"
#include "Repositories/RaceRecordRepository.h"
#include "Repositories/RaceRepository.h"
#include "Repositories/UserRepository.h"
#include "DBManagment/ConnectionKeeper.h"
#include "DBManagment/sqlite3.h"

class RepositoriesTests :public ::testing::Test {
protected:
	void SetUp() override {
		
	}

	void TearDown() override {
		CloseConnection();
	}

	std::string ExecuteSQL(std::string str){}
};

TEST_F(RepositoriesTests, HorseRepositoryAddTest) {
	Horse horse;
	horse.Age = 1;
	horse.Experience = 1;
	horse.Nickname = "A";
	horse.OwnerId = 1;
	horse.Price = 1;
	std::string sql = "SELECT COUNT(*) FROM Horse";

	auto countOfHorsesBeforeAdd = ExecuteSQL(sql);
	int num = stoi(countOfHorsesBeforeAdd);
	Add(horse);

	EXPECT_EQ(num, num + 1);
}

TEST_F(RepositoriesTests, HorseRepositoryDeleteTest) {
	std::string sql = "SELECT COUNT(*) FROM Horse";

	auto countOfHorsesBeforeAdd = ExecuteSQL(sql);
	int num = stoi(countOfHorsesBeforeAdd);
	DeleteHorse(1);

	EXPECT_EQ(num, num - 1);
}

TEST_F(RepositoriesTests, HorseRepositoryUpdateTest) {
	auto horse = GetHorse(1);
	EXPECT_NE(horse, NULL);

	std::string sql = "SELECT * FROM Horse WHERE Id = 1";
	auto info1 = ExecuteSQL(sql);
	horse.Nickname = "a";
	Update(horse);
	auto info2 = ExecuteSQL(sql);

	EXPECT_STRNE(info1.c_str(), info2.c_str());
}

TEST_F(RepositoriesTests, JockeyRepositoryAddTest) {
	Jockey jockey;
	jockey.Address = "a";
	jockey.Experience = 1;
	jockey.Name = "a";
	jockey.YearOfBirth = 1;
	std::string sql = "SELECT COUNT(*) FROM Jockey";

	auto countOfJockeysBeforeAdd = ExecuteSQL(sql);
	int num = stoi(countOfJockeysBeforeAdd);
	AddJockey(jockey);

	EXPECT_EQ(num, num + 1);
}

TEST_F(RepositoriesTests, JockeyRepositoryUpdateTest) {
	auto jockey = GetJockeyInfo(1);
	EXPECT_NE(jockey, NULL);

	std::string sql = "SELECT * FROM Jockey WHERE Id = 1";
	auto info1 = ExecuteSQL(sql);
	jockey.Name = "a";
	Update(jockey);
	auto info2 = ExecuteSQL(sql);

	EXPECT_STRNE(info1.c_str(), info2.c_str());
}

TEST_F(RepositoriesTests, JockeyRepositoryGetBestJockeyTest) {
	auto jockey = GetBestJockey();
	EXPECT_NE(jockey, NULL);
}

TEST_F(RepositoriesTests, OwnerRepositoryAddTest) {
	Owner owner;
	owner.Address = "a";
	owner.Name = "a";
	owner.YearOfBirth = 1;
	std::string sql = "SELECT COUNT(*) FROM Owner";

	auto countOfOwnersBeforeAdd = ExecuteSQL(sql);
	int num = stoi(countOfOwnersBeforeAdd);
	AddOwner(owner);

	EXPECT_EQ(num, num + 1);
}

TEST_F(RepositoriesTests, OwnerRepositoryUpdateTest) {
	auto owner = GetOwnerInfo(1);
	EXPECT_NE(owner, NULL);

	std::string sql = "SELECT * FROM Owner WHERE Id = 1";
	auto info1 = ExecuteSQL(sql);
	owner.Name = "a";
	Update(owner);
	auto info2 = ExecuteSQL(sql);

	EXPECT_STRNE(info1.c_str(), info2.c_str());
}

TEST_F(RepositoriesTests, OwnerRepositoryGetBestHorseTest) {
	auto horse = GetBestHorse(1);
	EXPECT_NE(horse, NULL);
}

TEST_F(RepositoriesTests, OwnerRepositoryGetHorsesByOwnerIdTest) {
	auto horses = GetHorsesByOwnerId(1);
	EXPECT_NE(horses.size(), 0);
}

TEST_F(RepositoriesTests, PrizeRepositoryGetAllTest) {
	auto info = GetAll();
	EXPECT_NE(info.size(), 0);
}

TEST_F(RepositoriesTests, RaceRecordRepositoryGetTest) {
	auto info1 = GetJockeyRecords(1);
	EXPECT_NE(info1.size(), 0);

	auto info2 = GetByHorseId(1);
	EXPECT_NE(info2.size(), 0);

	auto info3 = GetByPeriod("01.01.1970", "04.04.2022");
	EXPECT_NE(info3.size(), 0);
	
	auto info4 = GetByRaceId(1);
	EXPECT_NE(info4.size(), 0);
	
	auto info5 = GetRaceRecordById(1);
	EXPECT_NE(info5, NULL);
}

TEST_F(RepositoriesTests, RaceRecordRepositoryAddTest) {
	RaceRecord raceRecord;
	std::string sql = "SELECT COUNT(*) FROM RaceRecord";

	auto countOfRaceRecordsBeforeAdd = ExecuteSQL(sql);
	int num = stoi(countOfRaceRecordsBeforeAdd);
	AddRaceRecord(raceRecord);

	EXPECT_EQ(num, num + 1);
}

TEST_F(RepositoriesTests, RaceRepositoryAddTest) {
	Race race;
	race.Date = "04.04.2022";
	std::string sql = "SELECT COUNT(*) FROM Race";

	auto countOfRacesBeforeAdd = ExecuteSQL(sql);
	int num = stoi(countOfRacesBeforeAdd);
	AddRace(race);

	EXPECT_EQ(num, num + 1);
}

TEST_F(RepositoriesTests, RaceRepositoryUpdateTest) {
	Race race;
	race.Date = "04.04.2022";
	race.Id = 1;
	std::string sql = "SELECT * FROM Race WHERE Id = 1";

	auto info1 = ExecuteSQL(sql);
	UpdateRace(race);
	auto info2 = ExecuteSQL(sql);

	EXPECT_STRNE(info1.c_str(), info2.c_str());
}

TEST_F(RepositoriesTests, RaceRepositoryDeleteTest) {

	std::string sql = "SELECT COUNT(*) FROM Race";

	auto countOfRacesBeforeAdd = ExecuteSQL(sql);
	int num = stoi(countOfRacesBeforeAdd);
	DeleteRace(1);

	EXPECT_EQ(num, num - 1);
}

TEST_F(RepositoriesTests, UserRepositoryAddTest) {
	User user;
	user.Email = "a";
	user.PasswordSigned = "a";
	user.Role = _Jockey;
	std::string sql = "SELECT COUNT(*) FROM User";

	auto countOfUsersBeforeAdd = ExecuteSQL(sql);
	int num = stoi(countOfUsersBeforeAdd);
	AddUser(&user);

	EXPECT_EQ(num, num + 1);
}

TEST_F(RepositoriesTests, UserRepositoryGetTest) {
	auto user = TryGetUserByLogin("a");
	EXPECT_NE(user.size(), 0);
}