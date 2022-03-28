#include <stdio.h>

#include "DBManagment/includes/ConnectionKeeper.h"
#include "Repositories/UserRepository.h"
#include "Models/Authorization/User.h"

int main() {

	int rc = OpenConnection();

	User user;

	TryGetUserByLogin(&user, "Elza");

	int rs = CloseConnection();
	return 0;
}