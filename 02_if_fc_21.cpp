#include <iostream>

int main() {
  int a, b, c, d;

  std::cin >> a >> b >> c >> d;

  if (a > b) {
    std::swap(a, b);
    if (d >= a) {
      if (c > d)
        c -= a;
    } else
      c += a;

    b = a + c + d;
  }

  else {
    if (c > a && a >= b)
      d += a;
    if (d > c)
      b += 2;
    else
      b *= 2;
  }

  std::cout << a << " " << b << " " << c << " " << d << std::endl;
}
