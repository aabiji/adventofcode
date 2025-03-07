#include "lib.h"
#include <unordered_map>
#include <set>

int main() {
  auto lines = read_lines("inputs/day23.txt");

  std::unordered_map<std::string, std::set<std::string>> graph;
  for (auto line : lines) {
    auto parts = split(line, "-");
    graph[parts[0]].insert(parts[1]);
    graph[parts[1]].insert(parts[0]);
  }

  int count = 0;
  std::set<std::string> visited;

  for (auto pair : graph) {
    auto neighbors = pair.second;

    for (auto it1 = neighbors.begin(); it1 != neighbors.end(); it1++) {
      for (auto it2 = neighbors.begin(); it2 != neighbors.end(); it2++) {
        std::string a = pair.first, b = *it1, c = *it2;
        if (visited.count(a + "-" + b + "-" + c)) continue;

        // A needs to be connected to b and c
        // B needs to connected to C (we already know it's connected to A)
        // C needs to be connected B (we already know it's connected to A
        bool connected = graph[b].count(a) && graph[c].count(a) && graph[c].count(b) && graph[b].count(c);

        if (connected && (a[0] == 't' || b[0] == 't' || c[0] == 't'))
          count++;

        // We've already considered all the permuatations of a, b and c
        std::string parts[3] = { a, b, c };
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
              visited.insert(parts[i] + "-" + parts[j] + "-" + parts[k]);
            }
          }
        }
      }
    }
  }

  std::cout << count << "\n";
}
