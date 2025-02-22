#include "lib.h"

int main() {
  std::vector<std::string> lines = read_lines("inputs/day15.txt");

  int list_start = 0;
  vec2 player;

  for (int y = 1; y < lines.size(); y++) {
    if (lines[y][0] != '#') {
      list_start = y + 1;
      break;
    }
    for (int x = 0; x < lines[y].length(); x++) {
      if (lines[y][x] == '@') {
        player = vec2(x, y);
        lines[y][x] = '.';
      }
    }
  }

  std::unordered_map<char, vec2> directions = {{'^', vec2(0, -1)},
                                               {'v', vec2(0, 1)},
                                               {'<', vec2(-1, 0)},
                                               {'>', vec2(1, 0)}};

  for (int i = list_start; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].length(); j++) {
      vec2 direction = directions[lines[i][j]];
      vec2 new_pos = player + direction;
      if (lines[new_pos.y][new_pos.x] == '#')
        continue; // Can't move into wall

      // Capture all the obstacles in the way
      vec2 obstacle_end = new_pos;
      while (lines[obstacle_end.y][obstacle_end.x] == 'O')
        obstacle_end += direction;
      if (lines[obstacle_end.y][obstacle_end.x] == '#')
        continue; // Can't move into wall

      // Move the obstacles and player
      while (obstacle_end != player) {
        vec2 opposite = obstacle_end - direction;
        lines[obstacle_end.y][obstacle_end.x] = lines[opposite.y][opposite.x];
        obstacle_end = opposite;
      }
      player = new_pos;
    }
  }

  int sum = 0;
  for (int y = 1; y < list_start - 1; y++) {
    for (int x = 0; x < lines[y].length(); x++) {
      if (lines[y][x] == 'O')
        sum += 100 * y + x;
    }
  }

  std::cout << sum << "\n";
}
