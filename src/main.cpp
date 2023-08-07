#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "cheat.hpp"
#include "cheat-invincibility.hpp"
#include "cheat-lockitemcount.hpp"
#include "cheat-lockspellcount.hpp"

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

void printStatus(std::string& name, std::map<std::string, Cheat*>& cheats, unsigned int pid)
{
	try {
		std::cout << name << ": " << (cheats.at(name)->status(pid) ? "enabled" : "disabled") << std::endl;
	} catch (...) {
		std::cerr << "[ERROR] Failed to get cheat status for \"" << name << '"' << std::endl;
	}
}

void handleStatus(std::vector<std::string>& tokens, std::map<std::string, Cheat*>& cheats, unsigned int pid)
{
	if (tokens.size() == 1)
		for (std::pair<std::string, Cheat*> pair : cheats)
			printStatus(pair.first, cheats, pid);
	else
		printStatus(tokens[1], cheats, pid);
}

void handleEnable(std::vector<std::string>& tokens, std::map<std::string, Cheat*>& cheats, unsigned int pid)
{
	if (tokens.size() != 2) return;
	try {
		cheats.at(tokens[1])->enable(pid);
	} catch (...) {
		std::cerr << "[ERROR] Failed to enable cheat: " << tokens[1] << std::endl;
	}
}

void handleDisable(std::vector<std::string>& tokens, std::map<std::string, Cheat*>& cheats, unsigned int pid)
{
	if (tokens.size() != 2) return;
	try {
		cheats.at(tokens[1])->disable(pid);
	} catch (...) {
		std::cerr << "[ERROR] Failed to disable cheat: " << tokens[1] << std::endl;
	}
}

int main(int argc, char** argv)
{
	unsigned int pid = 0;
	std::map<std::string, Cheat*> cheats;
	cheats["invincibility"] = new Invincibility();
	cheats["lockitemcount"] = new LockItemCount();
	cheats["lockspellcount"] = new LockSpellCount();
	while (true)
		try {
			std::cout << "> ";
			std::string input;

			std::getline(std::cin, input);
			if (std::cin.eof()) break;

			std::vector<std::string> tokens = tokenizeInput(input);
			if (tokens.empty()) continue;

			if (tokens[0] == "pid") handlePID(tokens, pid);
			else if (pid == 0) std::cerr << "[ERROR] PID not set" << std::endl;
			else if (tokens[0] == "status") handleStatus(tokens, cheats, pid);
			else if (tokens[0] == "enable") handleEnable(tokens, cheats, pid);
			else if (tokens[0] == "disable") handleDisable(tokens, cheats, pid);
			else std::cerr << "[ERROR] Unknown command: " << tokens[0] << std::endl;

		} catch (...) {
			std::cerr << "[ERROR] Something Happened :(" << std::endl;
		}

	for (const std::pair<std::string, Cheat*>& pair : cheats)
		delete pair.second;

	std::cout << std::endl;
	return 0;
}
