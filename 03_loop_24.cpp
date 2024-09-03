#include <iostream>
#include <string>

int main() {
  std::string input;
  std::cin >> input;

  if (input.empty())
    return 0;

  char buffer{input[0]};
  int amount{1};

  bool printed{false};
  for (int i{1}; i < input.length(); ++i) {
    if (input[i] == buffer)
      amount++;

    else {
      (printed && std::cout << " ") || (printed = true);
      std::cout << buffer << " " << amount;
      buffer = input[i];
      amount = 1;
    }
  }

  if (amount) {
    (printed && std::cout << " ") || (printed = true);
    std::cout << buffer << " " << amount;
  }
}
