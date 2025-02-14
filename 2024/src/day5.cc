#include <algorithm>
#include <unordered_map>
#include "lib.h"

int main() {
  std::vector<std::string> lines = read_lines("inputs/day5.txt");
  int list_start_index = 0;

  // Map a number to a list of numbers that could come before it
  std::unordered_map<int, std::vector<int>> before;

  // Parse the page ordering rules
  for (int i = 0; i < lines.size(); i++) {
    std::string line = lines[i];
    if (line.length() == 0) {
      list_start_index = i;
      break;
    }
    std::vector<int> nums = split_num<int>(line, "|");
    before[nums[1]].push_back(nums[0]);
  }

  int sum = 0; // Sun of the seuence medians

  /*
  // Part 1: Get the sum of the median of the sequences that are ordered correctly
  for (int i = list_start_index + 1; i < lines.size(); i++) {
    std::string line = lines[i];
    std::vector<int> nums = split_num<int>(line, ",");
    bool valid_sequence = true;

    for (int j = 0; j < nums.size(); j++) {
      std::vector<int>& nums_before = before[nums[j]];
      if (nums_before.empty())
        continue;

      // we're cooked if we have something coming after that should come before
      for (int k = j; k < nums.size(); k++) {
         if (std::count(nums_before.begin(), nums_before.end(), nums[k])) {
          valid_sequence = false;
          break;
        }
      }
    }

    if (valid_sequence) {
      int middle = nums.size() / 2;
      sum += nums[middle];
    }
  }
  */

  // Part 2: Correct the incorrectly ordered sequences and get the sum of their median
  for (int i = list_start_index + 1; i < lines.size(); i++) {
    std::string line = lines[i];
    std::vector<int> nums = split_num<int>(line, ",");
    bool valid_sequence = true;
    
    for (int j = 0; j < nums.size(); j++) {
      std::vector<int>& nums_before = before[nums[j]];
      if (nums_before.empty())
        continue;

      // make the numbers that should come before actually come before
      for (int k = j; k < nums.size(); k++) {
         if (std::count(nums_before.begin(), nums_before.end(), nums[k])) {
           int n = nums[j];
           nums[j] = nums[k];
           nums[k] = n;
           j -= 1; // retry from the current index
           valid_sequence = false;
           break;
        }
      }
    }

    if (!valid_sequence) {
      int middle = nums.size() / 2;
      sum += nums[middle];
    }
  }

  std::cout << "Answer: " << sum << "\n";
}