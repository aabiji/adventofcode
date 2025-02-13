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

  double sum = 0;
  for (int i = 0; i < count; i++) {
    double x = (double)heights[i];
    double y = (double)heights[i + 1];
    double w = (double)widths[i];
    sum += (w * (x + y) / 2);
  }

  std::cout << sum << "\n";
}