#include <iostream>
#include <ostream>
#include <set>
#include <sstream>
#include <vector>

std::set<int> set_union(const std::vector<std::set<int>> &sets) {
  std::set<int> union_result;
  for (const std::set<int> &set : sets)
    union_result.insert(set.begin(), set.end());

  return union_result;
}

std::set<int> set_intersection(const std::vector<std::set<int>> &sets) {
  std::set<int> intersection_result(sets.front());

  for (auto it{std::next(sets.begin())}; it != sets.end(); ++it) {
    std::vector<int> to_erases;
    for (int element : intersection_result) {
      if (it->find(element) == it->end()) {
        to_erases.push_back(element);
      }
    }

    for (int to_erase : to_erases)
      intersection_result.erase(to_erase);
  }

  return intersection_result;
}

std::set<int> set_difference(const std::vector<std::set<int>> &sets) {
  std::set<int> difference_result(sets.front());

  for (auto it{std::next(sets.begin())}; it != sets.end(); ++it) {
    for (int element : *it)
      difference_result.erase(element);
  }

  return difference_result;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &set) {
  bool printed{false};
  for (const T &element : set) {
    (printed && std::cout << " ") || (printed = true);
    os << element;
  }

  if (!printed)
    os << "empty set";

  return os;
}

int main() {
  std::vector<std::set<int>> sets;
  std::istringstream iss;
  std::string line;

  while (std::getline(std::cin, line)) {
    iss.clear();
    iss.str(line);

    std::set<int> current_set;
    int number;

    while (iss >> number)
      current_set.insert(number);

    sets.push_back(current_set);
  }

  std::cout << "U: " << set_union(sets) << "\n";
  std::cout << "I: " << set_intersection(sets) << "\n";
  std::cout << "D: " << set_difference(sets) << "\n";
}
