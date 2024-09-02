#include <iostream>

int main() {
  int a, b, c, d, e;

  std::cin >> a >> b >> c >> d >> e;

  if (a > b)
    std::swap(a, b);

  if (c > d)
    std::swap(c, d);

  if (a > c) {
    std::swap(b, d);
    c = a;
  }

  a = e;

  if (a > b)
    std::swap(a, b);

  if (c > a) {
    std::swap(b, d);
    a = c;
  }

  if (a > d)
    std::cout << d << std::endl;
  else
    std::cout << a << std::endl;
}
