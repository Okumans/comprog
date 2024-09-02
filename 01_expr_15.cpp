#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
  double x;
  std::cin >> x;

  std::cout << std::fixed << std::setprecision(6)
            << std::pow(x, std::sqrt(std::log(std::pow(x + 1, 2)))) / (10 - x)
            << std::endl;
}
