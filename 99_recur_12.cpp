#include <cmath>
#include <iostream>

int mod(int a, int k, int m) {
  if (k == 0)
    return 1;

  if (k % 2)
    return a * static_cast<int>(std::pow(mod(a, k / 2, m), 2)) % m;

  if (!(k % 2))
    return static_cast<int>(std::pow(mod(a, k / 2, m), 2)) % m;

  throw "unreachable";
}

int main() {
  int a, k, m;

  std::cin >> a >> k >> m;
  std::cout << mod(a, k, m) << "\n";
}
