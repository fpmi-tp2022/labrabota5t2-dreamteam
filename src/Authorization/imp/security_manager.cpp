#include "../security_manager.h"
#include "../../Repositories/UserRepository.h"
#include "../sha256.h"
#include <iostream>

std::string GetHash(std::string str);

Result CheckLoginCollision(const std::string& login) {
	auto users = TryGetUserByLogin(login);
	if (users.size() > 0) {
		return Result::LOGIN_COLLISION;;
	}
	return Result::NO_ERROR;
}


Result VerifyCredentials(const std::string& login, const std::string& password) {
	auto users = TryGetUserByLogin(login);
	if (users.size() != 0) {
		return Result::LOGIN_COLLISION;
	}

	auto hash = GetHash(password);
	if (hash != users[0].PasswordSigned) {
		return Result::WRONG_PASSWORD;
	}
	std::cout << "Hash for " << password << '(' << hash << ')' << std::endl;
	return Result::NO_ERROR;
}

Result RegisterNewUser(const std::string& login, const std::string& password, Role role) {
	Result result = Result::NO_ERROR;
	if (FAILED(result = CheckLoginCollision(login))) {
		return result;
	}
	auto hash = GetHash(password);

	User user = {0, login, hash, role};
	return (Result)(0 == AddUser(&user));
}

std::string GetHash(std::string str) {
	return sha256(str);
}