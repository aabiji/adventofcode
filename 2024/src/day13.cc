#include "lib.h"
#include <sstream>

int main() {
  std::vector<std::string> lines = read_lines("inputs/day13.txt");

  long double total_cost = 0;

  for (long i = 0; i < lines.size(); i += 4) {
    // Get the numbers
    std::vector<unsigned long> nums;
    for (int j = 0; j < 3; j++) {
      std::vector<std::string> parts = split(lines[i + j], " ");
      int i = parts.size() - 1;
      int a = to_int(parts[i - 1].substr(2, parts[i - 1].length() - 3));
      int b = to_int(parts[i].substr(2, parts[i].length() - 2));
      nums.push_back(a);
      nums.push_back(b);
    }

    // Part 2
    //nums[4] += 10000000000000;
    //nums[5] += 10000000000000;

    // Solve the system of equations
    long double a = nums[0], b = nums[2], c = nums[1], d = nums[3];
    long double m = 1 / (a * d - b * c);
    long double matrix[4] = {d * m, -b * m, -c * m, a * m};
    long double x = matrix[0] * nums[4] + matrix[1] * nums[5];
    long double y = matrix[2] * nums[4] + matrix[3] * nums[5];

    // Is it a valid solution (int x and y)?
    std::stringstream ss;
    ss << std::fixed << x;
    ss << " ";
    ss << std::fixed << y;
    std::string fraction = ss.str().substr(ss.str().find(".") + 1, 6);

    // Add the minimum cost
    if (x >= 0 && y >= 0 && fraction == "000000")
      total_cost += x * 3 + y;
  }

  std::cout << "Total cost: " << std::fixed << total_cost << "\n";
}