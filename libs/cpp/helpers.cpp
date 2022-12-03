#include "helpers.hpp"
#include <iostream>

std::vector<std::string> splitPuzzleInputs(std::string inputs)
{
	int pointer = 0;
	std::string line;
	std::vector<std::string> lines;
	while (pointer < inputs.size()) {
		if (inputs[pointer] == '\n') {
			lines.push_back(line);
			line = "";
			pointer ++;
			continue;
		}
		line += inputs[pointer];
		pointer ++;
	}
	return lines;
}

std::string readPuzzleInputs(std::string filename)
{
	std::string inputs;
	std::fstream file(filename);
	
	if (!file.good()) {
		std::cout << "File not found.\n";
		return inputs;
	}

	char c;
	while (file.get(c)) {
		inputs += c;
	}
	file.close();
	return inputs;
}
