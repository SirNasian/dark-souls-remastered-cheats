#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenizeInput(std::string& input)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream iss(input);
	while (std::getline(iss, token, ' '))
	{
		std::transform(token.begin(), token.end(), token.begin(), [](unsigned char c){ return std::tolower(c); });
		tokens.push_back(token);
	}
	return tokens;
}

void handlePID(std::vector<std::string>& tokens, unsigned int& pid)
{
	try {
		pid = (tokens.size() == 2) ? std::stoi(tokens[1]) : 0;
		std::cout << "PID set to " << pid << std::endl;
	} catch (...) {
		std::cerr << "[ERROR] Failed to set PID" << std::endl;
	}
}

int main(int argc, char** argv)
{
	unsigned int pid = 0;
	while (true)
		try {
			std::cout << "> ";
			std::string input;

			std::getline(std::cin, input);
			if (std::cin.eof()) break;

			std::vector<std::string> tokens = tokenizeInput(input);
			if (tokens.empty()) continue;

			if (tokens[0] == "pid") handlePID(tokens, pid);
			else if (tokens[0] == "status") continue;
			else if (tokens[0] == "enable") continue;
			else if (tokens[0] == "disable") continue;
			else std::cerr << "[ERROR] Unknown command: " << tokens[0] << std::endl;

		} catch (...) {
			std::cerr << "[ERROR] Something Happened :(" << std::endl;
		}

	std::cout << std::endl;
	return 0;
}
