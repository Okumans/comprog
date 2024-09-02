#include <iostream>

int main() {
  float p{0}, t{1}, k{0};
  std::cin >> p;

  do {
    k += 1;
    t = (t * (365 - (k - 1))) / 365;
  } while (1 - t < p);

  std::cout << k << std::endl;
}
