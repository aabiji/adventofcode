#include <tuple>
#include "lib.h"

int main() {
    std::vector<std::string> lines = read_lines("inputs/day4.txt");
    int width = lines[0].size();
    int height = lines.size();

    int count = 0;
    std::tuple<int, int> directions[] = {
        { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 },
        { -1, -1 }, { 1, -1 }, { -1, 1 }, { 1, 1 }
    };

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (lines[y][x] != 'A')
                continue;

            std::string strings[8] = {"", "", "", "", "", "", "", ""};
            for (int d = 4; d < 8; d++) {
                int cx = x + std::get<0>(directions[d]);
                int cy = y + std::get<1>(directions[d]);
                if (cx < 0 || cx >= width || cy < 0 || cy >= height)
                    continue;
                strings[d] += lines[cy][cx];
            }

            std::string diag1 = strings[4] + "A" + strings[7];
            std::string diag2 = strings[5] + "A" + strings[6];
            if ((diag1 == "MAS" || diag1 == "SAM") &&
                (diag2 == "MAS" || diag2 == "SAM"))
                count++;

            /* For part 1:
            if (lines[y][x] != 'X')
                continue;

            // Go 4 times in each direction
            for (int i = 0; i < 4; i++) {
                for (int d = 0; d < 8; d++) {
                    int cx = x + i * std::get<0>(directions[d]);
                    int cy = y + i * std::get<1>(directions[d]);
                    if (cx < 0 || cx >= width || cy < 0 || cy >= height)
                        continue;
                    strings[d] += lines[cy][cx];
                }
            }

            for (std::string str : strings) {
                if (str == "XMAS" || str == "SMAX")
                    count++;
            }
            */
        }
    }

    std::cout << "Number of occurences: " << count << "\n";
}
