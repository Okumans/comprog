#include <iostream>

int main() {
  int weight, price;
  std::cin >> weight;

  if (weight <= 100)
    price = 18;
  else if (weight <= 250)
    price = 22;
  else if (weight <= 500)
    price = 28;
  else if (weight <= 1000)
    price = 38;
  else if (weight <= 2000)
    price = 58;
  else
    price = -1;

  if (price == -1)
    std::cout << "Reject" << std::endl;
  else
    std::cout << price << std::endl;
}
