#include "lib.h"
#include <queue>
#include <set>

// Count the number of places where the sequence isn't contiguous
int count_jumps_in_sequence(std::vector<int>& sequence) {
  int jumps = 1;
  int previous = sequence[0];
  for (int i = 1; i < sequence.size(); i++) {
    if (sequence[i] - previous != 1)
      jumps++;
    previous = sequence[i];
  }
  return jumps;
}

int main() {
  std::vector<std::string> lines = read_lines("inputs/day12.txt");
  int width = lines[0].length();
  int height = lines.size();

  int cost = 0;
  bool part_1 = false;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      char c = lines[y][x];
      if (c == '.') continue;

      // Breath first search to find the region
      std::queue<vec2> region;
      std::set<vec2> visited;

      region.push(vec2(x, y));
      visited.insert(vec2(x, y));

      while (!region.empty()) {
        vec2 p = region.front();
        region.pop();

        vec2 neighbors[] = {
            {p.x + 1, p.y}, {p.x - 1, p.y}, {p.x, p.y + 1}, {p.x, p.y - 1}};
        for (vec2 n : neighbors) {
          if (n.x >= 0 && n.x < width && n.y >= 0 && n.y < height &&
              lines[n.y][n.x] == c && visited.count(n) == 0) {
            region.push(n);
            visited.insert(n);
          }
        }
      }

      // Find the perimeter and the number of sides in the region
      int perimeter = 0;
      std::unordered_map<int, std::vector<int>> sides[4];

      for (vec2 p : visited) {
        int bordering_sides = 0;
        vec2 neighbors[] = {
            {p.x + 1, p.y}, {p.x - 1, p.y}, {p.x, p.y + 1}, {p.x, p.y - 1}};
        for (int i = 0; i < 4; i++) {
          if (!visited.count(neighbors[i])) {
            int a = i == 0 || i == 1 ? neighbors[i].x : neighbors[i].y;
            int b = i == 0 || i == 1 ? neighbors[i].y : neighbors[i].x;
            sides[i][a].push_back(b);
            bordering_sides++;
          }
        }
        lines[p.y][p.x] = '.'; // remove from map
        perimeter += bordering_sides;
      }

      int num_sides = 0;
      for (int i = 0; i < 4; i++) {
        for (auto pair : sides[i]) {
          num_sides += count_jumps_in_sequence(pair.second);
        }
      }

      cost += visited.size() * (part_1 ? perimeter : num_sides);
    }
  }

  std::cout << "Total cost: " << cost << "\n";
}