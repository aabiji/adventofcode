#include <iostream>
#include <vector>

using namespace std;

int main() {
  int count;
  vector<int> heights;
  vector<int> widths;

  cin >> count;
  for (int i = 0; i < count + 1; i++) {
    int j = 0;
    cin >> j;
    heights.push_back(j);
  }
  for (int i = 0; i < count; i++) {
    int j = 0;
    cin >> j;
    widths.push_back(j);
  }

  float sum = 0;
  for (int i = 0; i < count; i++) {
    float x = (float)heights[i];
    float y = (float)heights[i + 1];
    float w = (float)widths[i];
    sum += (w * (x + y) / 2);
  }

  std::cout << sum << "\n";
}