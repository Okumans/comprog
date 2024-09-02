#include <cmath>
#include <cstdint>
#include <iostream>

int main() {
  uint32_t width, height;
  double table[35][35];

  std::cin >> height >> width;

  for (uint32_t y{0}; y < height; ++y) {
    for (uint32_t x{0}; x < width; ++x) {
      std::cin >> table[y][x];
    }
  }

  for (uint32_t y{1}; y < height - 1; ++y) {
    for (uint32_t x{1}; x < width - 1; ++x) {
      std::cout << std::round(
                       ((table[y][x] + table[y - 1][x - 1] + table[y - 1][x] +
                         table[y][x - 1] + table[y + 1][x + 1] +
                         table[y + 1][x] + table[y][x + 1] +
                         table[y - 1][x + 1] + table[y + 1][x - 1]) /
                        9.0) *
                       100) /
                       100.0;

      (x != width - 2) && std::cout << " ";
    }

    std::cout << "\n";
  }
}
