#include <cstring>
#include <iomanip>
#include <iostream>

int main() {
  int seqs[500];
  int numbers;

  std::cin >> numbers;
  for (int i{0}; i < numbers; ++i) {
    std::cin >> seqs[i];

    double summation{static_cast<double>(seqs[i])};

    for (int j{i - 1}; j >= 0; --j) {
      summation = seqs[j] + (1.0 / summation);
    }

    std::cout << std::setprecision(10) << summation << "\n";
  }
}
