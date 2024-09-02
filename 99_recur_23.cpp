#include <cmath>
#include <iostream>
#include <map>

int F(int n) { // Fibonacci number
  if (n == 0 || n == 1)
    return n;

  if (n >= 1 && n % 2 == 0)
    return (2 * F(n/2 - 1) + F(n/2)) * F(n/2);

  if (n >= 2 && n % 2 == 1)
    return std::pow(F((n+1)/2), 2) + std::pow(F((n+1)/2 - 1), 2);

  throw "unreachable";
}

int M(int n) { // Motzkin number
  if (n == 0 || n == 1)
    return 1;

  if (n >= 2) {
    int summ{0};

    for (int k{0}; k <= n - 2; ++k) {
      summ += M(k) * M(n - 2 - k);
    }

    return M(n - 1) + summ;
  }

  throw "unreachable";
}

int S(int n) { // Schröder–Hipparchus Number
  if (n == 1 || n == 2)
    return 1;

  if (n >= 3) {
    return (1.0 / n) * ((6 * n - 9) * S(n - 1) - (n - 3) * S(n - 2));
  }

  throw "unreachable";
}

int D(int n) { // Derangement
  if (n == 0)
    return 1;

  if (n >= 1)
    return n * D(n - 1) + std::pow(-1, n);

  throw "unreachable";
}

int main() {
  std::map<std::string, int (*)(int)> func = {
      {"F", F}, {"M", M}, {"S", S}, {"D", D}};
  std::string fn;
  int p;
  while (std::cin >> fn >> p) {
    if (func.find(fn) != func.end())
      std::cout << fn << '(' << p << ") = " << func[fn](p) << "\n";
  }
  return 0;
}
