#include <iostream>
#include <regex>

#include "lib.h"

int main() {
    // Find all mul(x, y) in the file
    std::string file = read_file("inputs/day3.txt");
    std::regex expr("(mul\\([0-9]+,[0-9]+\\))||(do\\(\\))||(don't\\(\\))");
    auto matches = std::sregex_iterator(file.begin(), file.end(), expr);
    auto end = std::sregex_iterator();

    int result = 0;
    bool enabled = true;

    for (std::sregex_iterator i = matches; i != end; ++i) {
        std::string match = (*i).str();
        if (match.size() == 0) continue;

        if (match == "do()")
            enabled = true;
        else if (match == "don't()")
            enabled = false;
        else if (enabled) {
            std::string pair = match.substr(4, match.length() - 5);
            std::vector<std::string> nums = split(pair, ",");
            result += to_int(nums[0]) * to_int(nums[1]);
        }
    }

    std::cout << "Multiplication result: " << result << "\n";
}
