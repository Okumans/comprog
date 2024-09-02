#include <cmath>
#include <iomanip>
#include <iostream>

std::pair<double, double> solve_polynomial(double a, double b, double c) {
  double tmp{std::sqrt(b * b - 4 * a * c)};
  return {(-b - tmp) / (2 * a), (-b + tmp) / (2 * a)};
}

int main() {
  double a{}, b{}, c{};
  std::cin >> a >> b >> c;
  const auto [result_a, result_b]{solve_polynomial(a, b, c)};
  std::cout << std::fixed << std::setprecision(3) << result_a << " "
            << result_b;
}
