#include <iostream>
#include <vector>

int find_between(const std::vector<int> &cols, int start, int stop) {
  int start_h{std::min(cols[start], cols[stop])}, vol{0};
  for (int i{start + 1}; i < stop; i++)
    vol += std::max(0, start_h - cols[i]);
  return vol;
}

int main() {
  std::vector<int> col_sorted, cols;
  int n, mx, buff;

  std::cin >> n;
  std::cin >> buff;

  cols.push_back(buff);
  col_sorted.push_back(0);

  mx = cols.back();
  for (int i{1}; i < n; i++) {
    std::cin >> buff;
    cols.push_back(buff);

    if (i == 1 && cols[1] < cols[0])
      col_sorted.push_back(-1);

    if (col_sorted.back() == -1)
      col_sorted.back() = i;

    else if (mx < cols.back()) {
      col_sorted.back() = i;
      col_sorted.push_back(-1);
      mx = cols.back();
    }

    else if (cols[col_sorted.back()] < cols.back())
      col_sorted.back() = i;
  }

  int total_vol{0};
  for (int i{1}; i < col_sorted.size() && col_sorted[i] != -1; i++)
    total_vol += find_between(cols, col_sorted[i - 1], col_sorted[i]);

  std::cout << total_vol << std::endl;
}
