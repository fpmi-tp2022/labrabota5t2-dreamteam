#include "UIManager.h"
#include "../Models/Jockey.h"
#include "../Models/Owner.h"
#include "../Repositories/JockeyRepository.h"
#include "../Repositories/OwnerRepository.h"
#include "../Repositories/RaceRecordRepository.h"
#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

UIManager::UIManager(User user)
{
	this->user = user;
}

UIManager::~UIManager()
{
}

bool UIManager::ShowMenu()
{
	int choise = -1;

	while (choise != 0)
	{
		std::cout << "Menu:\n";
		std::cout << "1 - SELECT operations\n";
		std::cout << "2 - INSERT\n"; //TODO
		std::cout << "3 - DELETE\n"; //TODO
		std::cout << "4 - UPDATE\n"; //TODO
		std::cout << "0 - EXIT\n";
		
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			if(typeid(user).name() == typeid(Jockey).name())
				SelectForJockey();
			else if (typeid(user).name() == typeid(Owner).name()) {
				SelectForOwner();
			}
			else {
				SelectForAdmin();
			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4 :
			break;
		default:
			break;
		}
	}

	return true;
}

void UIManager::SelectForJockey()
{
	int choise = -1;

	while (choise != 0)
	{
		std::cout << "SELECT operations menu:\n";
		std::cout << "1 - The jockey who participates the most times in the races\n";
		std::cout << "2 - All races\n";
		std::cout << "3 - Your info\n";
		std::cout << "4 - Your races\n";
		std::cout << "0 - EXIT\n";

		std::cin >> choise;
		switch (choise)
		{
		case 1:
			PrintInfoAboutBestJockey();
			break;
		case 2:
			PrintInfoAboutAllRaces();
			break;
		case 3: {
			auto info1 = GetJockeyInfo(user.Id);
			PrintJockeyInfo(info1, true);
			break;
		}
			
		case 4:
		{
			auto info2 = GetJockeyRecords(user.Id);
			for (auto race : info2)
			{
				PrintRaceInfo(race);
			}
			break;
		}
			
		default:
			break;
		}
	}
}

void UIManager::SelectForOwner()
{
	int choise = -1;

	while (choise != 0)
	{
		std::cout << "SELECT operations menu:\n";
		std::cout << "1 - The jockey who participates the most times in the races\n";
		std::cout << "2 - All races\n";
		std::cout << "3 - The horse that wins the maximum number of times\n";
		std::cout << "4 - Info about your horses\n";
		std::cout << "0 - EXIT\n";

		std::cin >> choise;
		switch (choise)
		{
		case 1:
			PrintInfoAboutBestJockey();
			break;
		case 2:
			PrintInfoAboutAllRaces();
			break;
		case 3:
		{
			auto info1 = GetBestHorce(user.Id);
			PrintHorseInfo(info1);
			break;
		}
		case 4:
		{
			auto info2 = GetHorsesByOwnerId(user.Id);
			for (auto h : info2)
			{
				PrintHorseInfo(h);
			}
			break;
		}
		default:
			break;
		}
	}
}

void UIManager::SelectForAdmin() {
	int choise = -1;

	while (choise != 0)
	{
		std::cout << "SELECT operations menu:\n";
		std::cout << "1 - The jockey who participates the most times in the races\n";
		std::cout << "2 - All races\n";
		std::cout << "0 - EXIT\n";

		std::cin >> choise;
		switch (choise)
		{
		case 1:
			PrintInfoAboutBestJockey();
			break;
		case 2:
			PrintInfoAboutAllRaces();
			break;
		default:
			break;
		}
	}
}

void UIManager::PrintInfoAboutBestJockey()
{
	auto info = GetBestJockey();
	auto jockeyInfo = GetJockeyInfo(info.JockeyId);

	PrintJockeyInfo(jockeyInfo, false);
	std::cout << " ,race amount: " << info.RaceAmount << ";\n";
}

void UIManager::PrintInfoAboutAllRaces()
{
	std::string begin, end;
	std::cout << "Enter the beginning of the period:\n";
	std::cin >> begin;
	std::cout << "Enter the end of the period:\n";
	std::cin >> end;

	auto info = GetByPeriod(begin, end);
	for(auto race : info)
	{
		PrintRaceInfo(race);
	}
}

void UIManager::PrintHorseInfo(Horse horse)
{
	std::cout << "Horce id: " << horse.Id << " ,nickname: " << horse.Nickname << " ,owner: " << horse.Owner << " ,owner id: " << horse.OwnerId
		<< ", age:" << horse.Age << ", experience: " << horse.Experience << " ,price: " << horse.Price << ";\n";
}

void UIManager::PrintJockeyInfo(Jockey jockey, bool nextline)
{
	std::cout << "Jockey id: " << jockey.Id << " ,Name: " << jockey.Name << " ,year of birth: " << jockey.YearOfBirth << ", address: " << jockey.Adress << " ,jockey experience: " << jockey.Experience;
	if (nextline) {
		std::cout << ";\n";
	}
}

void UIManager::PrintRaceInfo(RaceRecord race)
{
	std::cout << "Race id: " << race.RaceId << ", jockey: " << race.Jockey->Name << ", jockey id: " << race.JockeyId
		<< " ,horse: " << race.Horse->Nickname << ", horse id: " << race.HorseId << ", result: " << race.Result << ";\n";
}
