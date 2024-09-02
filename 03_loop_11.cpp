#include <cmath>
#include <iostream>

int main() {
  int N{0};
  double num{0}, sum{0};
  std::cin >> num;

  while (num != -1) {
    sum += num;
    N++;
    std::cin >> num;
  }

  if (N == 0)
    std::cout << "No Data" << std::endl;
  else
    std::cout << std::round((sum / N) * 100) / 100 << std::endl;
}
