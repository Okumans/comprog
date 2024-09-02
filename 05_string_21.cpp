#include <iostream>
#include <string>

inline bool word_complete(char chr, const std::string &buffer) {
  return (
      std::isupper(chr) ||
      (buffer.size() && (std::isdigit(chr) && std::isalpha(buffer.back())) ||
       (std::isalpha(chr) && std::isdigit(buffer.back()))));
}

int main() {
  std::string input, buffer;
  std::getline(std::cin, input);

  bool is_first_printed{false};
  for (char chr : input) {
    if (word_complete(chr, buffer)) {
      if (!buffer.empty()) {
        std::cout << (is_first_printed ? ", " : "") << buffer;
        buffer.clear();
        is_first_printed = true;
      }
    }

    buffer += chr;
  }

  if (!buffer.empty()) {
    std::cout << (is_first_printed ? ", " : "") << buffer;
  }

  std::cout << std::endl;
}
