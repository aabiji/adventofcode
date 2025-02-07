#pragma once

#include <fstream>
#include <vector>

// Split a std::string with the delimeter
std::vector<std::string> split(std::string str, std::string delim) {
    std::vector<std::string> parts;
    size_t pos = 0;
    while ((pos = str.find(delim)) != std::string::npos) {
        std::string part = str.substr(0, pos);
        parts.push_back(part);
        str.erase(0, pos + delim.length());
    }
    parts.push_back(str);
    return parts;
}

std::string read_file(std::string path) {
    std::ifstream file(path);
    std::string contents = "";
    std::string line = "";
    while (getline(file, line)) {
        contents += line + "\n";
    }
    return contents;
}

int to_int(std::string str) {
    return atoi(str.c_str());
}
