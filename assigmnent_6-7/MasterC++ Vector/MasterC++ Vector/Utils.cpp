#include "Utils.h"
#include <sstream>

std::vector<std::string> tokenize(std::string str, char delimiter)
{
	std::vector<std::string> result;
	std::stringstream ss{ str };
	std::string smth{};
	while (getline(ss, smth, delimiter))
		result.push_back(smth);

	return result;
}
