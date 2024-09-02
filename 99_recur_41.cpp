#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

int n, a, b;
std::unordered_map<int, std::vector<int>> floors;
std::set<std::vector<int>> solutions;

void play(int current, std::vector<int> &passed) {
  if (current == b) {
    solutions.insert(passed);
    return;
  }

  for (int floor : floors[current]) {
    passed.push_back(floor);
    play(floor, passed);
    passed.pop_back();
  }
}

int main() {
  std::cin >> n >> a >> b;

  for (int i{0}; i < n; ++i) {
    int curr, des;
    std::cin >> curr >> des;

    floors[curr].push_back(des);
  }

  std::vector<int> temp;
  temp.push_back(a);

  play(a, temp);

  if (solutions.empty()) {
    std::cout << "no\n";
    return 0;
  }

  for (const auto &solution : solutions) {
    bool printed{false};

    for (int floor : solution) {
      (printed && std::cout << " -> ") || (printed = true);
      std::cout << floor;
    }

    std::cout << "\n";
  }
}
