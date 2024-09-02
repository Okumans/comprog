#include <cmath>
#include <iomanip>
#include <iostream>
#include <ostream>

inline double mosteller(double w, double h) { return std::sqrt(w * h) / 60.0; }

inline double haycock(double w, double h) {
  return 0.024265 * std::pow(w, 0.5378) * std::pow(h, 0.3964);
}

inline double boyd(double w, double h) {
  return 0.0333 * std::pow(w, 0.6157 - 0.0188 * std::log10(w)) *
         std::pow(h, 0.3);
}

int main() {
  double w{}, h{};
  std::cin >> w >> h;

  std::cout << std::setprecision(15) << mosteller(w, h) << "\n"
            << haycock(w, h) << "\n"
            << boyd(w, h) << std::endl;
}
