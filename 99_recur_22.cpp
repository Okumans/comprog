#include <cassert>
#include <iostream>
#include <map>

int F(int n);
int M(int n);

int H(int n) { // Tower of Hanoi
  if (n == 0)
    return 0;

  assert(n >= 1);
  return 2 * H(n - 1) + 1;
}

int C(int n) { // Catalan Number
  if (n == 0)
    return 1;

  n -= 1;
  assert(n >= 0);

  int summ{0};
  for (int k{0}; k <= n; ++k) {
    summ += C(k) * C(n - k);
  }

  return summ;
}

int F(int n) { // Female sequence
  if (n == 0)
    return 1;

  assert(n > 0);
  return n - M(F(n - 1));
}

int M(int n) { // Male sequence
  if (n == 0)
    return 0;

  assert(n > 0);
  return n - F(M(n - 1));
}

int main() {
  std::map<std::string, int (*)(int)> func = {
      {"H", H}, {"C", C}, {"F", F}, {"M", M}};
  std::string fn;
  int p;
  while (std::cin >> fn >> p) {
    if (func.find(fn) != func.end())
      std::cout << fn << '(' << p << ") = " << func[fn](p) << std::endl;
  }
  return 0;
}
