#include "../security_manager.h"
#include "../../Repositories/UserRepository.h"
#include "../sha256.h"
#include <iostream>

std::string GetHash(const std::string& str);

bool CheckLoginCollision(const std::string& login) {
	return false;
}

int VerifyCredentials(const std::string& login, const std::string& password) {
	auto hash = GetHash(password);
	std::cout << "Hash for " << password << '(' << hash << ')' << std::endl;
	return -1;
}

std::string GetHash(const std::string& str) {
	return sha256(str);
}