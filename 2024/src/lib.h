#pragma once

#include <fstream>
#include <vector>

std::string trim(std::string& str) {
    std::string copy = str;
    copy.erase(0, str.find_first_not_of("\n\r\v\f\r ")); // Left trim
    copy.erase(str.find_last_not_of("\n\r\v\f\r ") + 1); // Right trim
    return copy;
}

// Split a std::string with the delimeter
std::vector<std::string> split(std::string str, std::string delim) {
    size_t pos = 0;
    std::vector<std::string> parts;
    while ((pos = str.find(delim)) != std::string::npos) {
        std::string part = str.substr(0, pos);
        str.erase(0, pos + delim.length());
        if (trim(part).length() > 0)
            parts.push_back(part);
    }
    if (trim(str).length() > 0)
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
