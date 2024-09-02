#include <iostream>

int main() {
  unsigned int size;
  int values[100], top_count{0};
  std::cin >> size;

  if (size < 3) {
    std::cout << 0 << std::endl;
    return 0;
  }

  for (unsigned int i{0}; i < size; ++i) {
    std::cin >> values[i];
  }

  for (unsigned int i{1}; i < size - 1; ++i) {
    if (values[i - 1] < values[i] && values[i] > values[i + 1]) {
      top_count++;
    }
  }

  std::cout << top_count << std::endl;
}
