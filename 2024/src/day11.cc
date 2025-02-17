#include "lib.h"
#include <unordered_map>

int main() {
  std::string file = read_file("inputs/day11.txt");

  std::vector<long> sequence = split_num<long>(file, " ");
  // Map numbers to the number of times they appear
  std::unordered_map<long, long> numbers;
  for (long num : sequence) {
    numbers[num]++;
  }

  for (long i = 0; i < 75; i++) {
    std::unordered_map<long, long> new_map;
    for (auto& [n, count]: numbers) {
      std::string str = std::to_string(n);
      long half = str.length() / 2;
      if (n == 0) {
        new_map[1] += count;
      } else if (str.length() % 2 == 0) {
          int a = to_int(remove_prefix(str.substr(0, half), '0'));
          int b = to_int(remove_prefix(str.substr(half, half), '0'));
          new_map[a] += count;
          new_map[b] += count;
      } else {
        new_map[n * 2024] += count;
      }
    }
    numbers = new_map;
  }

  long total_count = 0;
  for (auto& pair : numbers) {
    total_count += pair.second;
  }

  std::cout << "Answer: " << total_count << "\n";
}