#include <algorithm>
#include <cstdint>
#include <iostream>

enum class Direction : uint8_t { UP, DOWN, SAME };

struct Lift {
  int32_t from;
  int32_t to;

  static Direction direction(int32_t from, int32_t to) {
    if (from < to)
      return Direction::UP;
    if (from > to)
      return Direction::DOWN;
    return Direction::SAME;
  }

  Direction direction() { return direction(from, to); }

  bool is_between(int32_t position) {
    if (direction() == Direction::UP &&
        (position >= this->from && position <= this->to))
      return true;

    if (direction() == Direction::DOWN &&
        (position <= this->from && position >= this->to))
      return true;

    return false;
  }

  int32_t test(int32_t from, int32_t to) {
    if (direction(from, to) != direction())
      return std::abs(from - this->to) + std::abs(to - from);

    if (is_between(from) && is_between(to))
      return 0;

    if (is_between(from) &&
        ((direction() == Direction::DOWN && to <= this->to) ||
         (direction() == Direction::UP && to >= this->to)))
      return std::abs(this->to - to);

    int32_t cost{0};
    if (direction() == Direction::SAME || !is_between(from))
      cost = std::abs(from - this->to);

    return cost + std::abs(to - from);
  }
};

int main() {
  Lift lifts[1000];
  uint32_t numbers, questions;

  std::cin >> numbers;
  // let lifts[0] be a null buffer
  for (uint32_t i{1}; i <= numbers; ++i) {
    int32_t lift_name;
    std::cin >> lift_name;
    std::cin >> lifts[lift_name].from >> lifts[lift_name].to;
  }

  std::cin >> questions;
  while (questions--) {
    int32_t from, to;
    std::cin >> from >> to;

    int32_t min{static_cast<int32_t>(1e9)};
    int32_t min_lift_name{0}; // 0 is not a valid name

    for (uint32_t i{1}; i <= numbers; ++i) {
      // std::cout << "test: " << lifts[i].test(from, to) << "\n";
      if (int32_t cost{lifts[i].test(from, to)}; cost < min) {
        min = cost;
        min_lift_name = i;
      }
    }

    std::cout << ">> " << min_lift_name << "\n";
  }
}
