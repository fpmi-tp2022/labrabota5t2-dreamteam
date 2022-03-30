#include "../JockeyRepository.h"

std::vector<JockeyExperince> GetJockeyExperience() 
{
	std::vector<JockeyExperince> results;
	return results;
}

JockeyExperince GetBestJockey() {
	auto jockeys = GetJockeyExperience();
	JockeyExperince answer = jockeys[0];

	for(auto j : jockeys)
	{
		if (j.RaceAmount > answer.RaceAmount) {
			answer = j;
		}
	}

	returm answer;
}