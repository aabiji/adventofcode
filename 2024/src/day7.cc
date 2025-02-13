#include <iostream>
#include "lib.h"

typedef unsigned long long u64;

// Get the number of possible equations formed using + or * or ||
// Basically just a simple recursion problem
bool eval(std::vector<u64> &nums, u64 target, u64 current, int i, int &count) {
  if (current > target) return false;
  if (i == nums.size()) return current == target;

  if (eval(nums, target, current + nums[i], i + 1, count)) count++;
  if (eval(nums, target, current * nums[i], i + 1, count)) count++;

  // Part 2
  u64 concat = to_int(std::to_string(current) + std::to_string(nums[i]));
  if (eval(nums, target, concat, i + 1, count)) count++;

  return false;
}

int main() {
  std::vector<std::string> lines = read_lines("inputs/day7.txt");

  u64 result = 0;
  for (std::string line : lines) {
    std::vector<std::string> parts = split(line, ": ");
    std::vector<u64> nums = split_num<u64>(parts[1], " ");
    u64 target = to_int(parts[0]);

    int count = 0;
    eval(nums, target, nums[0], 1, count);
    if (count > 0) result += target;
  }

  std::cout << "Total calibration result: " << result << "\n";
}