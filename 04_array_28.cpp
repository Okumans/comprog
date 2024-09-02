#include <cctype>
#include <cstdint>
#include <iostream>
#include <string>

uint8_t alphabets[30];
int main() {
  std::string input;

  std::getline(std::cin, input);
  for (char chr : input) {
    if (std::isalpha(chr)) {
      alphabets[std::tolower(chr) - 'a']++;
    }
  }

  for (int i{0}; i < 26; i++) {
    if (alphabets[i]) {
      std::cout << static_cast<char>('a' + i) << " -> "
                << static_cast<int>(alphabets[i]) << std::endl;
    }
  }
}
