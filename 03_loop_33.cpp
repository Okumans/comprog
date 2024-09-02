#include <iostream>

struct Case {
  int mn{static_cast<int>(1e9)};
  int mx{static_cast<int>(-1e9)};
};

int main() {
  int x, y, i{0};
  Case zag_zig, zig_zag;

  std::cin >> x;
  while (x != -998 && x != -999) {
    std::cin >> y;

    if (i++ % 2 == 0) {
      zag_zig.mn = std::min(zag_zig.mn, y);
      zag_zig.mx = std::max(zag_zig.mx, x);
      zig_zag.mn = std::min(zig_zag.mn, x);
      zig_zag.mx = std::max(zig_zag.mx, y);
    } else {
      zag_zig.mx = std::max(zag_zig.mx, y);
      zag_zig.mn = std::min(zag_zig.mn, x);
      zig_zag.mx = std::max(zig_zag.mx, x);
      zig_zag.mn = std::min(zig_zag.mn, y);
    }

    std::cin >> x;
  }

  if (x == -998)
    std::cout << zig_zag.mn << " " << zig_zag.mx << std::endl;
  else
    std::cout << zag_zig.mn << " " << zag_zig.mx << std::endl;
}
