#include <algorithm>
#include <iostream>
#include <queue>

constexpr int N{100100};

void print_array(int *pancakes, int n) {
  for (int i{0}; i < n; i++) {
    std::cout << (i == 0 ? "" : " ") << pancakes[i];
  }
  std::cout << std::endl;
}

int main() {
  int pancakes[N], n;
  std::priority_queue<int> pancakes_values;

  std::cin >> n;

  for (int i{0}; i < n; ++i) {
    std::cin >> pancakes[i];
    pancakes_values.push(pancakes[i]);
  }

  int sorted_level{0};

  print_array(pancakes, n);

  while (pancakes_values.size()) {
    bool is_sorted{true};

    if (pancakes[n - (sorted_level + 1)] != pancakes_values.top() &&
        pancakes[0] != pancakes_values.top()) {
      auto max_at{
          std::max_element(pancakes, pancakes + n - (sorted_level + 1))};
      std::reverse(pancakes, max_at + 1);
      is_sorted = false;
      print_array(pancakes, n);
    }

    if (pancakes[n - (sorted_level + 1)] != pancakes_values.top()) {
      std::reverse(pancakes, pancakes + n - sorted_level);
      is_sorted = false;
    }

    pancakes_values.pop();
    ++sorted_level;
    if (!is_sorted)
      print_array(pancakes, n);
  }
}
