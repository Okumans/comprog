#include <iostream>
#include <queue>

int main() {
  std::queue<int> stored_numbers;
  int n{0};

  std::cin >> n;
  stored_numbers.push(n);
  while (n != 1) {
    if (n % 2 == 0)
      n /= 2;
    else
      n = 3 * n + 1;

    stored_numbers.push(n);
    if (stored_numbers.size() > 15)
      stored_numbers.pop();
  }

  bool printed{false};
  while (stored_numbers.size()) {
    if (!printed)
      printed = true;
    else
      std::cout << "->";

    std::cout << stored_numbers.front();
    stored_numbers.pop();
  }
}
