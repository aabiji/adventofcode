#pragma once

#include <fstream>
#include <iostream>
#include <vector>

long long to_int(std::string str) {
    char* end;
    return strtol(str.c_str(), &end, 10);
}

std::string trim(std::string& str) {
    std::string copy = str;
    copy.erase(0, str.find_first_not_of("\n\r\v\f\r ")); // Left trim
    copy.erase(str.find_last_not_of("\n\r\v\f\r ") + 1); // Right trim
    return copy;
}

// Split a string with the delimeter
std::vector<std::string> split(std::string str, std::string delim) {
    size_t pos = 0;
    std::vector<std::string> parts;
    while ((pos = str.find(delim)) != std::string::npos) {
        std::string part = str.substr(0, pos);
        str.erase(0, pos + delim.length());
        parts.push_back(part);
    }
    if (trim(str).length() > 0)
        parts.push_back(str);
    return parts;
}

// Split a string with the delimeter into a list of numbers
template <typename T>
std::vector<T> split_num(std::string str, std::string delim) {
    size_t pos = 0;
    std::vector<T> nums;

    if (delim.length() == 0) {
        for (int i = 0; i < str.length() - 1; i++) {
            nums.push_back(to_int(str.substr(i, 1)));
        }
        return nums;
    }

    while ((pos = str.find(delim)) != std::string::npos) {
        std::string part = str.substr(0, pos);
        str.erase(0, pos + delim.length());
        nums.push_back(static_cast<T>(to_int(part)));
    }
    nums.push_back(static_cast<T>(to_int(str)));
    return nums;
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

std::vector<std::string> read_lines(std::string path) {
    return split(read_file(path), "\n");
}

// Output a list of numbers in rows
template <typename T>
void print_list(std::vector<T> nums, int row_size = 20) {
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && i % row_size == 0)
        std::cout << "\n";
      std::cout << nums[i] << " ";
    }
    std::cout << "\n";
}