#include <stdio.h>

#include "DBManagment/includes/ConnectionKeeper.h"
#include "Repositories/UserRepository.h"
#include "Models/Authorization/User.h"

int main() {

	int rc = OpenConnection();

	//get user by login sample
	User user;
	std::vector<User> vector = TryGetUserByLogin("Elza");

	//add new user
	User user2;
	user2.PasswordSigned = "456";
	user2.Email = "Pavel";
	user2.Role = (Role)2;
	AddUser(&user2);

	int rs = CloseConnection();
	return 0;
}