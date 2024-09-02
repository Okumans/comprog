#include <cstring>
#include <iostream>

inline bool check_phonenumber(char *buffer) {
  if (std::strlen(buffer) != 10)
    return false;

  if (buffer[0] != '0')
    return false;

  if (buffer[1] == '6' || buffer[1] == '8' || buffer[1] == '9')
    return true;

  return false;
}

int main() {
  char buffer[100];
  std::cin >> buffer;

  if (check_phonenumber(buffer))
    std::cout << "Mobile number" << std::endl;
  else
    std::cout << "Not a mobile number" << std::endl;
}
