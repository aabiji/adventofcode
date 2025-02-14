#include <unordered_map>
#include "lib.h"

struct vec2 { int x; int y; };

int main() {
  std::vector<std::string> lines = read_lines("inputs/day8.txt");
  int width = lines[0].length();
  int height = lines.size();

  std::unordered_map<char, std::vector<vec2>> antennas;
  std::unordered_map<std::string,bool> antinodes; // to avoid duplicates

  // Find the antennas
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (lines[y][x] != '.' && lines[y][x] != '#')
        antennas[lines[y][x]].push_back({ x, y });
    }
  }

  // Find the antinodes
  for (auto pair : antennas) {
    for (auto a : pair.second) {
      for (auto b : pair.second) {
        if (a.x == b.x && a.y == b.y) continue;
        vec2 dist = {a.x - b.x, a.y - b.y};

        vec2 c = {a.x + dist.x, a.y + dist.y};
        while (c.x >= 0 && c.y >= 0 && c.x < width && c.y < height) {
          antinodes[std::to_string(c.x) + "," + std::to_string(c.y)] = true;
          c.x += dist.x;
          c.y += dist.y;
        }

        vec2 d = {a.x - dist.x, a.y - dist.y};
        while (d.x >= 0 && d.y >= 0 && d.x < width && d.y < height) {
          antinodes[std::to_string(d.x) + "," + std::to_string(d.y)] = true;
          d.x -= dist.x;
          d.y -= dist.y;
        }

        /* Part 1:
        vec2 top = {a.x + dist.x, a.y + dist.y};
        vec2 bot = {b.x - dist.x, b.y - dist.y};
        if (top.x >= 0 && top.x < width && top.y >= 0 && top.y < height)
          antinodes[std::to_string(top.x) + " " + std::to_string(top.y)] = true;
        if (bot.x >= 0 && bot.x < width && bot.y >= 0 && bot.y < height)
          antinodes[std::to_string(bot.x) + " " + std::to_string(bot.y)] = true;
        */
      }
    }
  }

  std::cout << "Number of antinodes: " << antinodes.size() << "\n";
}
