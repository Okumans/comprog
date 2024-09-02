#include <iostream>
#include <string>

int main() {
  int k;
  std::string str;

  std::cin >> str;
  std::cin >> k;

  int curr_char_numbers{0};
  char curr_stored_char{};

  for (char curr : str) {
    if (curr != curr_stored_char) {
      if (curr_char_numbers < k)
        std::cout << std::string(curr_char_numbers, curr_stored_char);
      curr_char_numbers = 1;
      curr_stored_char = curr;
    } else
      curr_char_numbers++;
  }

  if (curr_char_numbers < k)
    std::cout << std::string(curr_char_numbers, curr_stored_char) << std::endl;
}
