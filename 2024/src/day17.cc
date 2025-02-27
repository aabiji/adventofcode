#include "lib.h"

int main() {
  int a = 0, b = 0, c = 0;
  std::vector<int> instructions;
  std::string original;

  std::vector<std::string> lines = read_lines("inputs/day17.txt");
  for (auto line : lines) {
    if (line.length() == 0) continue;
    std::vector<std::string> parts = split(line, ":");
    if (parts[0] == "Register A") a = to_int(parts[1]);
    if (parts[0] == "Register B") b = to_int(parts[1]);
    if (parts[0] == "Register C") c = to_int(parts[1]);
    if (parts[0] == "Program") {
      instructions = split_num<int>(parts[1], ",");
      original = trim(parts[1]);
    }
  }

  // Find the number we divide A by each time
  int divisor = 0;
  for (int i = 1; i < instructions.size(); i++) {
    if (instructions[i - 1] == 0)
      divisor = pow(2, instructions[i]);
  }

  // Find the maximum value the original A value can be
  int maximum_bits = log2(divisor) * instructions.size();
  long min_a = pow(2, maximum_bits - 3) - 1;
  long max_a = pow(2, maximum_bits) - 1;

  // 10:38
  
  // Find the minimum value of A that makes the program output the original input
  for (long j = min_a; j < max_a; j++) {
    int output_index = 0;
    bool matches_input = true;
    long a = j, b = 0, c = 0;

    for (int i = 0; i < instructions.size(); i += 2) {
      long opcode = instructions[i];
      long literal = instructions[i + 1];
      long combo = literal <= 3 ? literal : literal == 4 ? a : literal == 5 ? b : c;
      if (opcode == 0) a = long(double(a) / double(divisor));
      if (opcode == 6) b = long((double)a / pow(2, combo));
      if (opcode == 7) c = long((double)a / pow(2, combo));
      if (opcode == 1) b ^= literal;
      if (opcode == 4) b ^= c;
      if (opcode == 2) b = combo % 8;
      if (opcode == 3 && a > 0) i = literal - 2;
      if (opcode == 5) {
        int digit = combo % 8;
        if (instructions[output_index++] != digit) {
          matches_input = false;
          break;
        }
      }
    }

    if (matches_input) {
      std::cout << "Found A: " << j << "\n";
      break;
    }
  }
}