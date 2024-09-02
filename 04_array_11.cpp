#include <array>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <string>

int main() {
  std::array<int8_t, 15> digits;
  std::string input;
  digits.fill(0);

  std::getline(std::cin, input);
  for (char chr : input) {
    if (std::isdigit(chr)) {
      digits[chr - '0']++;
    }
  }

  bool is_first_printed{false};
  for (int i{0}; i <= 9; i++) {
    if (!digits[i]) {
      std::cout << (is_first_printed ? "," : "") << i;
      is_first_printed = true;
    }
  }

  if (!is_first_printed) {
    std::cout << "None";
  }

  std::cout << std::endl;
}
