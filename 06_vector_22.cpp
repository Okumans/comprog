#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

struct Position {
  int value;
  int start;
  int stop;

  bool operator<(const Position &other) const {
    if (stop - start == other.stop - other.start) {
      return value < other.value;
    }
    return (stop - start < other.stop - other.start);
  }
};

int main() {
  std::vector<Position> positions;

  int buffer;
  int last_buffer{-435923847}; // random number
  int start_new_buffer{0};
  int curr_position{0};

  while (std::cin >> buffer) {
    if (buffer != last_buffer) {
      positions.push_back({last_buffer, start_new_buffer, curr_position});
      last_buffer = buffer;
      start_new_buffer = curr_position;
    }

    curr_position++;
  }

  positions.push_back({last_buffer, start_new_buffer, curr_position});

  std::sort(positions.begin(), positions.end());

  for (auto position : positions) {
    if (position.stop - position.start ==
        positions.back().stop - positions.back().start)
      std::cout << position.value << " --> x[ " << position.start << " : "
                << position.stop << " ]\n";
  }
}
