#include <iostream>
#include <string>

int main() {
  std::string expression;
  std::getline(std::cin, expression);

  for (char chr : expression) {
    if (chr == '[')
      chr = '(';
    else if (chr == '(')
      chr = '[';
    else if (chr == ']')
      chr = ')';
    else if (chr == ')')
      chr = ']';

    std::cout << chr;
  }
}
