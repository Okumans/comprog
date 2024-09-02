#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>
#include <vector>

struct Sum {
  std::vector<int> values;
  int summation{0};

  void add(int value) {
    summation += value;
    values.push_back(value);
  }

  int add_valid(int value) const {
    return summation + value <= 100 ? summation + value : 0;
  }

  int get_summation() const { return summation; }

  bool operator>(const Sum &other) const {
    return (summation == other.summation)
               ? (values.size() == other.values.size())
                     ? values < other.values
                     : values.size() < other.values.size()
               : summation > other.summation;
  }

  Sum(int init) : summation{init}, values{init} {}

  void sort() { std::sort(values.begin(), values.end()); }
};

void first(const std::vector<int> &inputs) {
  std::vector<Sum> results;

  for (const int input : inputs) {
    bool added{false};
    for (Sum &target_block : results) {
      if (target_block.add_valid(input)) {
        target_block.add(input);
        added = true;
        break;
      }
    }

    if (!added) {
      results.push_back(Sum(input));
    }
  }

  for (Sum &target_block : results)
    target_block.sort();

  sort(results.begin(), results.end(), std::greater<Sum>());
  for (Sum &target_block : results) {
    bool printed{false};
    for (int element : target_block.values) {
      (printed && std::cout << " ") || (printed = true);
      std::cout << element;
    }
    std::cout << "\n";
  }
}

void best(const std::vector<int> &inputs) {
  std::vector<Sum> results;

  for (const int input : inputs) {
    bool added{false};
    int max{static_cast<int>(-1e9)};
    Sum *max_sum{nullptr};

    for (Sum &target_block : results) {
      int current_block_value{target_block.add_valid(input)};
      if (current_block_value) {

        added = true;
        if (current_block_value > max) {
          max = current_block_value;
          max_sum = &target_block;
        }
      }
    }

    if (!added) {
      results.push_back(Sum(input));
    } else {
      max_sum->add(input);
    }
  }

  for (Sum &target_block : results)
    target_block.sort();

  sort(results.begin(), results.end(), std::greater<Sum>());
  for (Sum &target_block : results) {
    bool printed{false};
    for (int element : target_block.values) {
      (printed && std::cout << " ") || (printed = true);
      std::cout << element;
    }
    std::cout << "\n";
  }
}

int main() {
  std::string mode;
  std::vector<int> input;
  std::cin >> mode;

  int buffer;
  while (std::cin >> buffer && buffer != -666) {
    input.push_back(buffer);
  }

  if (mode == "first")
    first(input);
  else if (mode == "best")
    best(input);
}
