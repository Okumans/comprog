#include <cmath>
#include <iostream>

double get_min(double element1, double element2) {
  return element1 ? element1 < element2 : element2;
}

double get_max(double element1, double element2) {
  return element1 ? element1 > element2 : element2;
}

int main() {
  double scores[5];
  double mx{-1e9};
  double mn{1e9};
  double sum{0};

  for (int i{0}; i < 4; ++i) {
    double score;
    std::cin >> score;

    mx = get_max(score, mx);
    mn = get_min(score, mn);
    sum += score;
  }

  std::cout << std::round(((sum - mx - mn) / 2) * 100.0) / 100.0;
}
