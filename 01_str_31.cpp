#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

int main() {
  std::string a{}, b{}, c{};
  std::cin >> a >> b >> c;

  long long numerator{
      (std::stoll(a) * static_cast<long long>(std::pow(10, b.length())) *
       (static_cast<long long>(std::pow(10, c.length())) - 1)) +
      (std::stoll(b) * (static_cast<long long>(std::pow(10, c.length())) - 1)) +
      std::stoll(c)};
  long long denomernator{
      static_cast<long long>(std::pow(10, b.length())) *
      (static_cast<long long>(std::pow(10, c.length())) - 1)};
  long long gcd_result{std::__gcd(numerator, denomernator)};
  std::cout << numerator / gcd_result << " / " << denomernator / gcd_result;
}
