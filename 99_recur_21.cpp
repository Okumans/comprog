#include <iostream>
const int R = 7, C = 7;
const int diri[] = {1, 0, -1, 0};
const int dirj[] = {0, 1, 0, -1};

void floodfill(int x[][C], int r, int c, int e) {
  if (r < 0 || r >= R || c < 0 || c >= C)
    return;

  if (x[r][c] != 0)
    return;

  x[r][c] = e;

  for (int i{0}; i < 4; ++i) {
    floodfill(x, r + diri[i], c + dirj[i], e);
  }
}

int main() {
  int x[][C] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}};
  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      std::cin >> x[r][c];
  int row, col, e;
  std::cin >> row >> col >> e;
  floodfill(x, row, col, e);
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c)
      std::cout << x[r][c] << ' ';
    std::cout << '\n';
  }
}
