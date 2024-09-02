#include <cctype>
#include <cstring>
#include <iostream>

bool check(char *id) {
  if (std::strlen(id) != 2)
    return false;

  if (!std::isdigit(id[0]) || !std::isdigit(id[1]))
    return false;

  int num_id{std::atoi(id)};
  if (1 <= num_id && num_id <= 2)
    return true;

  if (20 <= num_id && num_id <= 40)
    return true;

  if (num_id == 51 || num_id == 53 || num_id == 55 || num_id == 58)
    return true;

  return false;
}

int main() {
  char input_id[100];
  std::cin >> input_id;

  if (check(input_id))
    std::cout << "OK";
  else
    std::cout << "Error";
}
