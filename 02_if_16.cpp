#include <iostream>

int main() {
  int number;
  std::cin >> number;

  if (number > 0)
    std::cout << "positive\n";
  else if (number == 0)
    std::cout << "zero\n";
  else
    std::cout << "negative\n";

  if (number % 2 == 0)
    std::cout << "even" << std::endl;
  else
    std::cout << "odd" << std::endl;
}
