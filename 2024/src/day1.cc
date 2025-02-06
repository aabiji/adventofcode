#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>

using namespace std;

// Split a string with the delimeter
vector<string> split(string str, string delim) {
    vector<string> parts;
    size_t pos = 0;
    while ((pos = str.find(delim)) != string::npos) {
        string part = str.substr(0, pos);
        parts.push_back(part);
        str.erase(0, pos + delim.length());
    }
    parts.push_back(str);
    return parts;
}

string readFile(string path) {
    ifstream file(path);
    string contents = "";
    string line = "";
    while (getline(file, line)) {
        contents += line + "\n";
    }
    return contents;
}

bool comp(int a, int b) {
    return a < b;
}

int main() {
    string file = readFile("inputs/day1.txt");
    vector<string> lines = split(file, "\n");

    // Left and right columns of numbers
    vector<int> left = {};
    vector<int> right = {};
    // Maps a number to how many times it appears in the right column
    unordered_map<int, int> frequencies = {};

    for (string line : lines) {
        vector<string> parts = split(line, "  ");
        if (parts.size() != 2) continue;
        int r = atoi(parts[1].c_str());

        left.push_back(atoi(parts[0].c_str()));
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

    int distanceSum = 0;
    int similarityScore = 0;

    for (int i = 0; i < left.size(); i++) {
        int l = left[i];
        distanceSum += abs(l - right[i]);;
        similarityScore += l * frequencies[l];
    }

    // Part 1 answer
    std::cout << "Sum of distances: " << distanceSum << "\n";
    // Part 2 answer
    std::cout << "Similarity score: " << similarityScore << "\n";
}
