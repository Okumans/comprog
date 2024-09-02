#include <iostream>

int main() {
  int year{};
  std::cin >> year;

  int y = (year - 543) % 100;
  std::cout << (y + (y / 4) + 11) % 7;
}
