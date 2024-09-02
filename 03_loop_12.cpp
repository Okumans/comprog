#include <cmath>
#include <iostream>

double bisection_log(double a) {
  double l{0}, u{a}, x{0};
  x = (l + u) / 2;

  while (std::abs(a - std::pow(10, x)) >
         10e-10 * std::fmax(a, std::pow(10, x))) {
    if (std::pow(10, x) > a)
      u = x;

    if (std::pow(10, x) < a)
      l = x;

    x = (l + u) / 2;
  }

  return x;
}

int main() {
  double n;
  std::cin >> n;
  std::cout << std::round(bisection_log(n) * 100000) / 100000 << std::endl;
}
