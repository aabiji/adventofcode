#include "../libs/cpp/helpers.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>

char match_outcome(char vs, char you)
{
	char outcome;
	if (you == 'X'      && vs == 'C') outcome = 'W';
	else if (you == 'Z' && vs == 'B') outcome = 'W';
	else if (you == 'Y' && vs == 'A') outcome = 'W';
	else if (you == 'Y' && vs == 'C') outcome = 'L';
	else if (you == 'X' && vs == 'B') outcome = 'L';
	else if (you == 'Z' && vs == 'A') outcome = 'L';
	else outcome = 'D';
	return outcome;
}

char determine_play(char vs, char you)
{
	std::map<char, int> win;
	std::map<char, int> lose;
	win['C'] = 'X';
	win['B'] = 'Z';
	win['A'] = 'Y';
	lose['C'] = 'Y';
	lose['B'] = 'X';
	lose['A'] = 'Z';
	char your_play;
	if (you == 'X') your_play = lose[vs];
	if (you == 'Z') your_play = win[vs];
	if (you == 'Y') your_play = vs + 23;
	return your_play;
}

int main()
{
	std::vector<std::string> inputs = splitPuzzleInputs(readPuzzleInputs("inputs/day2.txt"));
	std::map<char, int> points;
	int part1_total_score = 0;
	int part2_total_score = 0;
	points['X'] = 1;
	points['Y'] = 2;
	points['Z'] = 3;
	points['L'] = 0;
	points['D'] = 3;
	points['W'] = 6;

	for (std::string line: inputs) {
		part1_total_score += points[match_outcome(line[0], line[2])];
		part1_total_score += points[line[2]];
		
		char you = determine_play(line[0], line[2]);
		part2_total_score += points[match_outcome(line[0], you)];
		part2_total_score += points[you];
	}
	std::cout << "Part 1: " << part1_total_score << "\n";
	std::cout << "Part 2: " << part2_total_score << "\n";
}
