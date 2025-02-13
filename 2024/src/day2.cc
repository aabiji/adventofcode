#include <iostream>

#include "lib.h"

bool valid_sequence(std::vector<std::string> nums) {
    int first_diff = to_int(nums[0]) - to_int(nums[1]);

    // Get the indexes of the wrong numbers
    for (int i = 1; i < nums.size(); i++) {
        // Diff between the previous and this number
        int diff = to_int(nums[i - 1]) - to_int(nums[i]);
        // The two numbers have the same sign and have a difference between 0 and 3
        bool works = ((diff * first_diff) > 0) && (abs(diff) > 0 && abs(diff) <=3);
        if (!works) return false;
    }

    return true;
}

int main() {
    std::vector<std::string> lines = read_lines("inputs/day2.txt");
    int safe_count = 0; // Number of reports that are safe

    for (std::string line : lines) {
        if (line.size() == 0) continue;
        std::vector<std::string> nums = split(line, " ");
        bool safe = false;
        if (valid_sequence(nums)) {
            safe = true;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                std::vector<std::string> copy = nums;
                copy.erase(copy.begin() + i);
                if (valid_sequence(copy)) {
                    safe = true;
                    break;
                }
            }
        }

        if (safe)
            safe_count++;
    }

    std::cout << "Number of safe reports: " << safe_count << "\n";
}
