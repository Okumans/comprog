#include <iostream>
#include <set>

std::set<int> yon{4, 6, 9, 11};

int main() {
  int d, m, y, n;

  std::cin >> d >> m >> y;

  y -= 543;
  n = 31;

  if (yon.find(m) != yon.end())
    n = 30;

  else {
    if (m == 2) {
      n = 28;
      if (y % 400 == 0)
        n = 29;
      if ((y % 4 == 0) && (y % 100 != 0))
        n = 29;
    }
  }

  d += 15;
  if (d > n) {
    d -= n;
    m += 1;
  }

  if (m > 12) {
    m -= 12;
    y += 1;
  }

  y += 543;

  std::cout << d << "/" << m << "/" << y << std::endl;
}
