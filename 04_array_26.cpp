#include <iostream>

int count_inversion(int *table, int n) {
  int count{0};
  for (int i{0}; i < n; i++) {
    for (int j{i + 1}; j < n; j++) {
      if (!table[i] || !table[j])
        continue;
      count += (table[i] > table[j]);
    }
  }

  return count;
}

bool is_valid(int n, int inversion_counted, int zero_at) {
  if (n % 2 != 0 && inversion_counted % 2 == 0)
    return true;

  if (n % 2 != 0)
    return false;

  if (inversion_counted % 2 == 0 && zero_at / n % 2 != 0)
    return true;

  if (inversion_counted % 2 != 0 && zero_at / n % 2 == 0)
    return true;

  return false;
}

int main() {
  int n, zero_at;
  int table[10000];

  std::cin >> n;

  for (int i{0}; i < n * n; i++) {
    std::cin >> table[i];
    if (!table[i])
      zero_at = i;
  }

  if (is_valid(n, count_inversion(table, n * n), zero_at))
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}
