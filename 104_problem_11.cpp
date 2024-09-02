#include <iostream>

int size;
char table[25][25];

bool can_place(int start_x, int start_y) {
  // check for horizontal line
  for (int x{0}; x < size; ++x) {
    if (x != start_x && table[start_y][x] == 'Q')
      return false;
  }

  // check for vertical line
  for (int y{0}; y < size; ++y) {
    if (y != start_y && table[y][start_x] == 'Q')
      return false;
  }

  // for left -> right cross
  for (int x{start_x}, y{start_y}; x < size; ++x, --y) {
    if (x != start_x && y != start_y && table[y][x] == 'Q')
      return false;
  }

  for (int x{start_x}, y{start_y}; x >= 0; --x, ++y) {
    if (x != start_x && y != start_y && table[y][x] == 'Q')
      return false;
  }

  // for right -> left cross
  for (int x{start_x}, y{start_y}; x >= 0; --x, --y) {
    if (x != start_x && y != start_y && table[y][x] == 'Q')
      return false;
  }

  for (int x{start_x}, y{start_y}; x < size; ++x, ++y) {
    if (x != start_x && y != start_y && table[y][x] == 'Q')
      return false;
  }

  return true;
}

int main() {
  std::cin >> size;

  for (int y{0}; y < size; ++y) {
    for (int x{0}; x < size; ++x) {
      std::cin >> table[y][x];
    }
  }

  for (int y{0}; y < size; ++y) {
    for (int x{0}; x < size; ++x) {
      if (table[y][x] == 'Q' && can_place(x, y))
        std::cout << 'Q';
      else
        std::cout << '-';
    }
    std::cout << "\n";
  }
}
