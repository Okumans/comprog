#include <cmath>
#include <iostream>

int main() {
  double subscribers;
  char postfix{'\0'};

  std::cin >> subscribers;

  if (subscribers >= 1e9) {
    subscribers /= 1e9;
    postfix = 'B';
  }

  else if (subscribers >= 1e6) {
    subscribers /= 1e6;
    postfix = 'M';
  }

  else if (subscribers >= 1e3) {
    subscribers /= 1e3;
    postfix = 'K';
  }

  if (subscribers > 10)
    subscribers = std::round(subscribers);
  else
    subscribers = std::round(subscribers * 10) / 10;

  std::cout << subscribers;
  postfix && (std::cout << postfix);
}
