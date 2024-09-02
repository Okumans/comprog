#include <iostream>
#include <unordered_set>

int main() {
  std::unordered_set<int> set;
  int count{0}, buffer;

  while (std::cin >> buffer && ++count) {
    if (set.find(buffer) != set.end()) {
      std::cout << count << "\n";
      return 0;
    }

    set.insert(buffer);
  }

  std::cout << -1 << "\n";
}
