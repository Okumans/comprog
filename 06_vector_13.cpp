#include <iostream>
#include <vector>
std::vector<std::string> split(std::string line, char delimiter) {
  std::vector<std::string> elements;
  std::string buffer;

  for (char chr : line) {
    if (chr == delimiter) {
      if (buffer.length())
        elements.emplace_back(std::move(buffer));
      buffer.clear();
    }

    else {
      buffer += chr;
    }
  }

  if (buffer.length())
    elements.emplace_back(std::move(buffer));

  return elements;
}

int main() {
  std::string line;
  std::string delim;

  std::getline(std::cin, line);
  std::getline(std::cin, delim);

  for (const std::string &element : split(line, delim[0])) {
    std::cout << '(' << element << ')';
  }
}
