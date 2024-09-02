#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string target_word;
  std::string paragraph;

  std::getline(std::cin, target_word);
  std::getline(std::cin, paragraph);

  std::string buffer;
  uint32_t count{0};

  for (size_t ind{0}; ind <= paragraph.length(); ++ind) {
    if (std::isalpha(paragraph[ind]))
      buffer += paragraph[ind];
    else {
      count += (buffer == target_word);
      buffer.clear();
    }
  }

  std::cout << count << "\n";
}
