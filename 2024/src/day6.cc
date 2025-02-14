#include <unordered_map>
#include "lib.h"

struct vec2 {
  int x; int y;
  bool operator==(const vec2 &other) const {
    return x == other.x && y == other.y;
  }
};

struct vec2_hasher {
  size_t operator()(const vec2 &p) const {
    return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
  }
};

int main() {
  std::vector<std::string> lines = read_lines("inputs/day6.txt");

  int width = lines[0].length();
  int height = lines.size();

  // Find the player
  vec2 player;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (lines[i][j] == '^') {
        player.x = j;
        player.y = i;
      }
    }
  }

  // Getting the path taken on the original map
  vec2 pos = player;
  int i = 0; // direction
  int steps = 0;
  std::unordered_map<vec2, bool, vec2_hasher> path;
  vec2 directions[] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

  while (pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height) {
    // Change direction if the next position is an obstacle
    if (pos.x + directions[i].x >= 0 && pos.x + directions[i].x < width &&
        pos.y + directions[i].y >= 0 && pos.y + directions[i].y < height &&
        lines[pos.y + directions[i].y][pos.x + directions[i].x] == '#') {
      i = (i + 1) % 4;
      continue;
    }

    if (!path[pos]) {
      steps++;
      path[pos] = true;
    }
    pos.x += directions[i].x;
    pos.y += directions[i].y;
  }

  // Put obstacles on all the visited positions and
  // simulate whether we get into cycles
  int cycles = 0;
  for (auto pair : path) {
    if (pair.first.x == player.x && pair.first.y == player.y)
      continue;

    std::vector<std::string> copy = lines;
    copy[pair.first.y][pair.first.x] = '#';

    int i = 0; // direction
    std::unordered_map<std::string, bool> visited;
    vec2 pos = player;

    while (pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height) {
      // Change direction if the next position is an obstacle
      if (pos.x + directions[i].x >= 0 && pos.x + directions[i].x < width &&
          pos.y + directions[i].y >= 0 && pos.y + directions[i].y < height &&
          copy[pos.y + directions[i].y][pos.x + directions[i].x] == '#') {
        i = (i + 1) % 4;
        continue;
      }

      std::string s = std::to_string(pos.x) + "," + std::to_string(pos.y) + "," + std::to_string(i);
      if (!visited[s]) {
        visited[s] = true;
      } else { // we're in a loop
        cycles++;
        break;
      }
      pos.x += directions[i].x;
      pos.y += directions[i].y;
    }

  }

  std::cout << "Number of steps: " << steps << "\n";
  std::cout << "Number of possible cycles: " << cycles << "\n";
}