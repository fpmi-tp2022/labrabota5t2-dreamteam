#include <stdio.h>

#include "DBManagment/includes/ConnectionKeeper.h"
#include "Repositories/UserRepository.h"
#include "Models/Authorization/User.h"
#include "Repositories/RaceRecordRepository.h"
#include "Models/RaceRecord.h"
#include "Repositories/OwnerRepository.h"

int main() {

	int rc = OpenConnection();

	std::vector<RaceRecord> vector = GetByPeriod(std::string("20020000"), std::string("30000000"));
	std::vector<Horse> horses = GetHorsesByOwnerId(1);
	std::vector<RaceRecord> v2 = GetByHorseId(1);
	std::vector<RaceRecord> v3 = GetByHorseId(2);
	int rs = CloseConnection();
	return 0;
}