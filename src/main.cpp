#include <stdio.h>

#include "DBManagment/includes/ConnectionKeeper.h"
#include "Repositories/UserRepository.h"
#include "Models/Authorization/User.h"
#include "Repositories/RaceRecordRepository.h"
#include "Models/RaceRecord.h"
#include "Repositories/OwnerRepository.h"
#include "Repositories/JockeyRepository.h"
#include "Repositories/HorseRepository.h"

int main() {

	int rc = OpenConnection();

	std::vector<RaceRecord> vector = GetByPeriod(std::string("20020000"), std::string("30000000"));
	std::vector<Horse> horses = GetHorsesByOwnerId(1);
	std::vector<RaceRecord> v2 = GetByHorseId(1);
	std::vector<RaceRecord> v3 = GetByHorseId(2);

	Jockey j = GetJockeyInfo(1);
	j.Name = "Pawel";
	j.Address = "Warsaw";

	Update(j);

	Jockey j2 = GetJockeyInfo(1);

	std::vector<JockeyExperince> je = GetJockeyExperience();
	std::vector<HorseResults> hr = GetHorsesWon();
	
	int rs = CloseConnection();
	return 0;
}