#include <deque>
#include <iostream>
#include <queue>
#include <sstream>

int main() {
  int count{0};
  int n{0}, buffer{0};
  std::deque<int> queue;

  std::cin >> n;
  for (int i{0}; i < n; ++i) {
    std::cin >> buffer;

    if (count++ % 2 == 0)
      queue.push_back(buffer);
    else
      queue.push_front(buffer);
  }

  std::cin.ignore();
  std::string input_buffer;
  std::getline(std::cin, input_buffer);

  std::istringstream iss(input_buffer);
  while (iss >> buffer) {
    if (count++ % 2 == 0)
      queue.push_back(buffer);
    else
      queue.push_front(buffer);
  }

  while (std::cin >> buffer && buffer != -1) {
    if (count++ % 2 == 0)
      queue.push_back(buffer);
    else
      queue.push_front(buffer);
  }

  bool printed{false};
  for (auto element : queue) {
    if (!printed) {
      printed = true;
      std::cout << "[";
    } else {
      std::cout << ", ";
    }
    std::cout << element;
  }

  std::cout << "]\n";
}
