#pragma once

#include <cmath>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

long long to_int(std::string str) {
  char *end;
  return strtol(str.c_str(), &end, 10);
}

long long to_int(char c) { return to_int(std::to_string(c)); }

// Output a list of numbers in rows
template <typename T> void print_nums(std::vector<T> nums, int row_size = 20) {
  for (int i = 0; i < nums.size(); i++) {
    if (i > 0 && i % row_size == 0)
      std::cout << "\n";
    std::cout << nums[i] << " ";
  }
  std::cout << "\n";
}

std::string trim(std::string &str) {
  std::string copy = str;
  copy.erase(0, str.find_first_not_of("\n\r\v\f\r ")); // Left trim
  int last = str.find_last_not_of("\n\r\v\f\r ") + 1;
  if (last < copy.length())
    copy.erase(last); // Right trim
  return copy;
}

std::string remove_prefix(std::string str, char c) {
  std::string copy = str;
  copy.erase(0, str.find_first_not_of(c));
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

struct vec2 {
  int x, y;

  vec2(int _x, int _y) {
    x = _x;
    y = _y;
  }

  vec2() {
    x = 0;
    y = 0;
  }

  bool operator==(const vec2 &other) const {
    return x == other.x && y == other.y;
  }

  bool operator!=(const vec2 &other) const {
    return x != other.x || y != other.y;
  }

  bool operator<(const vec2 &other) const {
    return x < other.x || (x == other.x && y < other.y);
  }

  vec2 &operator+=(const vec2 &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  friend vec2 operator+(vec2 lhs, const vec2 &rhs) {
    lhs += rhs;
    return lhs;
  }

  friend vec2 operator-(vec2 lhs, const vec2 &rhs) {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
  }
};

template <> struct std::hash<vec2> {
  size_t operator()(const vec2 &v) const noexcept {
    return std::hash<int>()(v.x) ^ (std::hash<int>()(v.y) << 1);
  }
};
