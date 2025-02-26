#include "lib.h"

int main() {
    int a = 0, b = 0, c = 0;
    std::vector<int> instructions;
    std::string output = "";

    // work our way backwards???
    std::vector<std::string> lines = read_lines("inputs/day17.txt");
    for (auto line : lines) {
        if (line.length() == 0) continue;
        std::vector<std::string> parts = split(line, ":");
        if (parts[0] == "Register A") a = to_int(parts[1]);
        if (parts[0] == "Register B") b = to_int(parts[1]);
        if (parts[0] == "Register C") c = to_int(parts[1]);
        if (parts[0] == "Program") instructions = split_num<int>(parts[1], ",");
    }

    for (int i = 0; i < instructions.size(); i += 2) {
        int opcode = instructions[i];
        int literal = instructions[i + 1];
        int combo = literal <= 3 ? literal : literal == 4 ? a : literal == 5 ? b : c;
        if (opcode == 0) a = (int)((double)a / pow(2, combo));
        if (opcode == 6) b = (int)((double)a / pow(2, combo));
        if (opcode == 7) c = (int)((double)a / pow(2, combo));
        if (opcode == 5) output += std::to_string(combo % 8) + ",";
        if (opcode == 1) b ^= literal;
        if (opcode == 4) b ^= c;
        if (opcode == 2) b = combo % 8;
        if (opcode == 3 && a > 0) i = literal - 2;
    }
    output = output.substr(0, output.length() - 1); // remove ending ,

    std::cout << output << "\n";
}