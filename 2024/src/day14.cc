#include "lib.h"

inline int mod(int a, int b) {
    return (a % b + b) % b;
}

struct Robot {
    vec2 position;
    vec2 velocity;

    Robot(std::vector<int> coordinates, std::vector<int> velocities) {
        position.x = coordinates[0];
        position.y = coordinates[1];
        velocity.x = velocities[0];
        velocity.y = velocities[1];
    }

    void step(int width, int height) {
        position.x = mod((position.x + velocity.x), width);
        position.y = mod((position.y + velocity.y), height);
    }
};

int main() {
    std::vector<Robot> bots;

    std::vector<std::string> lines = read_lines("inputs/day14.txt");
    for (auto line : lines) {
        auto parts = split(line, " ");
        auto coordinates = split_num<int>(parts[0].substr(2, parts[0].length()), ",");
        auto velocities = split_num<int>(parts[1].substr(2, parts[1].length()), ",");
        bots.push_back(Robot(coordinates, velocities));
    }

    int w = 101, h = 103;
    int half_w = w / 2, half_h = h / 2;
    int quads[4] = {0, 0, 0, 0};

    int iteration = 1;
    int min_safety = 100000000;
    int min_safety_iter = 0;

    while (true) {
        quads[0] = quads[1] = quads[2] = quads[3] = 0;
        for (auto& bot : bots) {
            bot.step(w, h);
            if (bot.position.x < half_w && bot.position.y < half_h)
                quads[0]++;
            if (bot.position.x > half_w && bot.position.y < half_h)
                quads[1]++;
            if (bot.position.x < half_w && bot.position.y > half_h)
                quads[2]++;
            if (bot.position.x > half_w && bot.position.y > half_h)
                quads[3]++;
        }
        int safety = quads[0] * quads[1] * quads[2] * quads[3];
        if (safety < min_safety) {
            min_safety = safety;
            min_safety_iter = iteration;
        }
        std::cout << iteration << " " << safety << " Min: " << min_safety << " @ " << min_safety_iter << "\n";
        iteration++;
    }
}