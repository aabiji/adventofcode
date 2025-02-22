#include "lib.h"

// Part 1: Count the number of '9' height positions from the current trailhead
// Part 2: Count the numbe of ways you could reach the '9 height position
void count_trailheads(
    std::vector<std::string>& grid,
    std::unordered_map<std::string, bool>& visited,
    int x, int y, int& score
) {
    if (grid[y][x] == '9')
        score++; // Found a valid path

    int width = grid[0].length();
    int height = grid.size();
    int neighbors[4][2] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};

    for (auto pos : neighbors) {
        std::string key = std::to_string(pos[0]) + "," + std::to_string(pos[1]);
        if (pos[0] < 0 || pos[0] >= width || pos[1] < 0 || pos[1] >= height)
            continue; // Out of range
        if (to_int(grid[pos[1]][pos[0]]) - to_int(grid[y][x]) != 1)
            continue; // Must be stepping by 1
        // Uncomment for Part 1:
        //if (visited.count(key))
        //    continue; // Already visited
        //visited[key] = true;
        count_trailheads(grid, visited, pos[0], pos[1], score);
    }
}

int main() {
    std::vector<std::string> lines = read_lines("inputs/day10.txt");
    int score = 0;
    for (int y = 0; y < lines.size(); y++) {
        for (int x = 0; x < lines[0].length(); x++) {
            std::unordered_map<std::string, bool> visited;
            if (lines[y][x] == '0') {
                count_trailheads(lines, visited, x, y, score);
            }
        }
    }
    std::cout << "Score: " << score << '\n';
}
