#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
  int rows = 0;
  cin >> rows;

  int cols = 0;
  cin >> cols;

  int count = 0;
  cin >> count;

  unordered_map<string, int> cells;

  // r n -> every cell in row n is toggled
  // c n -> every cell in column n is toggled
  // select row -> answer += cols
  // selct col -> answer += rows
  for (int i = 0; i < count; i++) {
    char type = 0;
    cin >> type;
    int n = 0;
    cin >> n;

    if (type == 'R') { // row
      for (int j = 1; j <= cols; j++) {
        string str = std::to_string(j) + "," + std::to_string(n);
        if (cells.count(str) == 0)
          cells[str] = 1;
        else
          cells[str] = cells[str] == 0 ? 1 : 0;
      }
    }

    if (type == 'C') { // col
      for (int j = 1; j <= rows; j++) {
        string str = std::to_string(n) + "," + std::to_string(j);
        if (cells.count(str) == 0)
          cells[str] = 1;
        else
          cells[str] = cells[str] == 0 ? 1 : 0;
      }
    }
  }

  int answer = 0;
  for (auto pair : cells) {
    if (cells[pair.first] == 1) answer++;
  }

  std::cout << answer << "\n";
}
