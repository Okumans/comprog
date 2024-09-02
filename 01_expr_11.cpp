#include <cmath>
#include <iostream>

int factorial(int n) {
  int result{1};
  for (int i = 1; i <= n; ++i)
    result *= i;
  return result;
}

double to_radians(double degree) { return degree * M_PI / 180; }

int main() {
  std::cout << (M_PI - (static_cast<double>(factorial(10)) / std::pow(8, 8)) +
                std::pow(std::log(9.7),
                         7 / std::sqrt(71) - std::sin(to_radians(40)))) /
                   std::pow(1.2, std::pow(2.3, 1.0 / 3));
}
