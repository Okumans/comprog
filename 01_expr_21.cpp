#include <iostream>

int main() {
  int h1, m1, s1;
  int h2, m2, s2;

  std::cin >> h1 >> m1 >> s1;
  std::cin >> h2 >> m2 >> s2;

  int total_s1{h1 * 3600 + m1 * 60 + s1};
  int total_s2{h2 * 3600 + m2 * 60 + s2 + 3600 * 24};

  int total_diff{(total_s2 - total_s1) % (3600 * 24)};

  int result_h{total_diff / 3600};
  int result_m{(total_diff % 3600) / 60};
  int result_s{(total_diff % 3600) % 60};

  std::cout << result_h << ":" << result_m << ":" << result_s << std::endl;
}
