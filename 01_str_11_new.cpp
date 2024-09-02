#include <iostream>

long long powerOf10(int exponent) {
  long long result{1};
  for (size_t i{0}; i < exponent; ++i) {
    result *= 10;
  }
  return result;
}

int get_digit(long long number, size_t at) {
  return number % powerOf10(at + 1) / powerOf10(at);
}

int check(long long id) {
  int result{0};
  for (size_t i{2}; i < 14; ++i)
    result += i * get_digit(id, i - 2);
  return (11 - result % 11) % 10;
}

int main() {
  long long id{};
  std::cin >> id;

  for (int i{11}; i >= 0; --i) {
    std::cout << get_digit(id, i);
    if (i == 0 || i == 2 || i == 7 || i == 11)
      std::cout << "-";
  }
  std::cout << check(id) << std::endl;
}
