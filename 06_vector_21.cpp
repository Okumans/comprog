#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

std::string BWT(const std::string &original) {
  std::string result;
  std::vector<std::string> states;
  std::deque<char> queue(original.begin(), original.end());
  queue.push_back('$');

  for (int i{0}; i < queue.size(); ++i) {
    char front{queue.front()};
    queue.pop_front();
    queue.push_back(front);

    states.emplace_back(queue.begin(), queue.end());
  }

  std::sort(states.begin(), states.end());
  for (const auto &state : states) {
    result += state.back();
  }

  return result;
}

int main() {
  std::string original;
  std::cin >> original;
  std::cout << BWT(original) << std::endl;
}
