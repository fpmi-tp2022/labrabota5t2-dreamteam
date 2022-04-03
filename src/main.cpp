#include <stdio.h>

#include "DBManagment/ConnectionKeeper.h"
#include "Repositories/UserRepository.h"
#include "Models/Authorization/User.h"
#include "Repositories/RaceRecordRepository.h"
#include "Models/RaceRecord.h"
#include "Repositories/OwnerRepository.h"
#include "Repositories/JockeyRepository.h"
#include "Repositories/HorseRepository.h"
#include "Repositories/RaceRepository.h"
#include "Repositories/PrizeRepository.h"
#include "UserInteraction/UIManager.h"
#include "Authorization/auth_controller.h"

int main() {

	int rc = OpenConnection("../../hippodrome.db");

	UserSession session = Authorization();

	std::vector<RaceRecord> vector = GetByPeriod(std::string("20020000"), std::string("30000000"));
	std::vector<RaceRecord> v2 = GetByHorseId(1);
	std::vector<RaceRecord> v3 = GetByHorseId(2);

	Jockey j = GetJockeyInfo(1);
	j.Name = "Pawel";
	j.Address = "Warsaw";

	//Update(j);

	Jockey j2 = GetJockeyInfo(1);

	Owner o = GetOwnerInfo(1);
	o.Name = "Alzbieta";
	o.YearOfBirth = 1900;
	Update(o);
	Owner o2 = GetOwnerInfo(1);

	Horse h;
	h.Id = 2;
	h.Age = 12;
	h.Experience = 30.4;
	h.Nickname = "Viena";
	h.OwnerId = 1;
	h.Price = 23.4;

	//Update(h);

	std::vector<Horse> horses = GetHorsesByOwnerId(1);

	std::vector<JockeyExperince> je = GetJockeyExperience();
	std::vector<HorseResults> hr = GetHorsesWon();

	Jockey jo = GetJockeyByIdentityId(3);
	Owner o21 = GetOwnerByIdentityId(7);

	Race rrrr;
	rrrr.Date = "20131210";
	rrrr.Id = 3;
	rrrr.Date = "20010101";

	//UpdateRace(rrrr);
	//AddRace(rrrr);

	RaceRecord raceRecord;

	raceRecord.HorseId = 1;
	raceRecord.JockeyId = 1;
	raceRecord.RaceId = 2;
	raceRecord.Result = 35;

	//AddRaceRecord(raceRecord);

	//DeleteRace(2);

	//DeleteHorse(1);

	Jockey ooo;
	ooo.Address = "Minsk";
	ooo.IdentityId = 1;
	ooo.Name = "Alzbieta";
	ooo.YearOfBirth = 2010;
	//AddJockey(ooo);

	//GivePrize(1000, 1);
	std::vector<Prize> prizes = GetAll();

	int rs = CloseConnection();
	return 0;

}