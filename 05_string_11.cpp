#include <iostream>
#include <string>

inline void decode(const std::string &content) {
  char key{content.back()};
  bool encounter_key{false};
  std::string buffer;

  for (size_t i{0}; i < content.length() - 1; ++i) {
    if (content[i] == key && !encounter_key)
      encounter_key = true;

    else if (content[i] == key && encounter_key) {
      if (buffer.size())
        std::cout << buffer;
      buffer.clear();
      encounter_key = false;
    }

    else if (encounter_key) {
      buffer += content[i];
    }
  }

  std::cout << std::endl;
}

int main() {
  std::string input;

  while (std::getline(std::cin, input)) {
    decode(input);
  }
}
