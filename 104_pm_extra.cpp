#include <iostream>
#include <unordered_map>
#include <vector>

struct Mode {
  std::unordered_map<int, int> values;
  int mxx{static_cast<int>(-1e9)};
  std::unordered_map<int, int>::iterator max_pointer{nullptr};

  void add(int value) {
    if (++values[value] > mxx) {
      mxx = values[value];
      max_pointer = values.find(value);
    }

    else if (values[value] == mxx && max_pointer->first > value) {
      max_pointer = values.find(value);
    }
  }

  int get_max() const {
    return (max_pointer != nullptr && max_pointer != values.end())
               ? max_pointer->first
               : -1;
  }

  Mode(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (auto it{begin}; it != end; ++it) {
      if (*it)
        add(*it);
    }
  }
};

int main() {
  int k, N, M;
  std::cin >> k >> N >> M;

  std::vector<int> days(N, 0);
  for (int i{0}; i < M; ++i) {
    int day, temp;
    std::cin >> day >> temp;

    days[day - 1] = temp;
  }

  int buffer{0};
  bool printed{false};
  for (int i{0}; i < N; ++i) {
    auto start = days.begin() + std::max(0, i - k);
    auto end = days.begin() + std::min(N, i + k + 1);

    (printed && std::cout << ' ') || (printed = true);

    if ((buffer = Mode(start, end).get_max()) != -1)
      std::cout << buffer;
    else
      std::cout << 'X';
  }
}
