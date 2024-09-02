#include <iostream>

int main() {
  int n;
  std::cin >> n;

  std::cout << std::string(n - 1, '.') << "*\n";

  for (int i{1}; i < n - 1; i++) {
    std::cout << std::string(n - 1 - i, '.') << '*'
              << std::string(i * 2 - 1, '.') << "*\n";
  }

  std::cout << std::string(n * 2 - 1, '*') << std::endl;
}
