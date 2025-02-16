#include "lib.h"

int main() {
  std::string file = read_file("inputs/day11.txt");
  std::vector<long> sequence = split_num<long>(file, " ");

  for (long i = 0; i < 75; i++) {
    std::vector<long> new_sequence;
    for (long n : sequence) {
      std::string str = std::to_string(n);
      long half = str.length() / 2;

      if (n == 0) {
        new_sequence.push_back(1);
      } else if (str.length() % 2 == 0) {
        new_sequence.push_back(to_int(remove_prefix(str.substr(0, half), '0')));
        new_sequence.push_back(to_int(remove_prefix(str.substr(half, half), '0')));
      } else {
        new_sequence.push_back(n * 2024);
      }
    }
    sequence = new_sequence;
  }

  std::cout << "Answer: " << sequence.size() << "\n";
}