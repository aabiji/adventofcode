#include "lib.h"

// direction: 0 -> right, 1 -> down, 2 -> left, 3 -> up 
void shortest_path(std::vector<std::string>& grid, vec2 p, int d, int& cost) {
    // TODO: backtrack on dead ends

    vec2 positions[4] = {
        vec2(p.x + 1, p.y), vec2(p.x, p.y + 1),
        vec2(p.x - 1, p.y), vec2(p.x, p.y - 1)
    };

    while (grid[positions[d].y][positions[d].x] == '#') {
        d = (d + 1) % 4;
        cost += 1000;
    }

    cost++;
    shortest_path(grid, positions[d], d, cost);
}

int main() {
    vec2 initial;
    const int height = 15;
    std::vector<std::string> grid;
    for (int i = 0; i < height; i++) {
        std::string row;
        std::cin >> row;
        grid.push_back(row);
        int index = row.find("E");
        if (index != std::string::npos) {
            initial.x = index;
            initial.y = i;
        }
    }

    int cost = 0;
    shortest_path(grid, initial, 1, cost);
    std::cout << "Cost: " << cost << "\n";
}
