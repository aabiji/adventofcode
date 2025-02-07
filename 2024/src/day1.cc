#include <iostream>
#include <algorithm>
#include <cassert>
#include <unordered_map>

#include "lib.h"

using namespace std;

bool comp(int a, int b) {
    return a < b;
}

int main() {
    string file = read_file("inputs/day1.txt");
    vector<string> lines = split(file, "\n");

    // Left and right columns of numbers
    vector<int> left = {};
    vector<int> right = {};
    // Maps a number to how many times it appears in the right column
    unordered_map<int, int> frequencies = {};

    for (string line : lines) {
        vector<string> parts = split(line, "  ");
        if (parts.size() != 2) continue;
        int r = to_int(parts[1]);

        left.push_back(to_int(parts[0]));
        right.push_back(r);

        if (frequencies.count(r)) {
            frequencies[r] += 1;
        } else {
            frequencies.insert({ r, 1 });
        }
    }

    // Sort in ascending order
    sort(left.begin(), left.end(), comp);
    sort(right.begin(), right.end(), comp);
    assert(left.size() == right.size());

    int distance_sum = 0;
    int similarity_score = 0;

    for (int i = 0; i < left.size(); i++) {
        int l = left[i];
        distance_sum += abs(l - right[i]);;
        similarity_score += l * frequencies[l];
    }

    // Part 1 answer
    std::cout << "Sum of distances: " << distance_sum << "\n";
    // Part 2 answer
    std::cout << "Similarity score: " << similarity_score << "\n";
}
