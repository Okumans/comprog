#include <algorithm>
#include <cstdint>
#include <iostream>
#include <sys/types.h>

uint32_t get_volume(uint32_t *cols, uint32_t start, uint32_t stop) {
  uint32_t minn{std::min(cols[start], cols[stop])};
  uint32_t volume{0};
  for (uint32_t ind{start}; ind < stop; ++ind)
    volume += cols[ind] - minn;
  return volume;
}

int main() {
  uint32_t col_numbers;
  uint32_t cols[100];

  std::cin >> col_numbers;

  uint32_t current_max{0}, last_max{0};
  for (uint32_t i{0}; i < col_numbers; i++) {
    std::cin >> cols[i];
    if (cols[i] > last_max) {
      last_max = current_max;
      current_max = cols[i];
    }
  }
}
