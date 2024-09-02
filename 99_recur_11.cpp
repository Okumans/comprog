#include <iostream>

// string dec2bin(int d) {
//   if (d < 2)
//     return (d == 0 ? "0" : "1");
//   return dec2bin(d / 2) + dec2bin(d % 2);
// }

std::string dec2hex(int d) {
  if (d < 10)
    return std::string(1, '0' + d);

  if (d < 16)
    return std::string(1, 'A' + d - 10);

  return dec2hex(d / 16) + dec2hex(d % 16);
}

int main() {
  int d;
  while (std::cin >> d) {
    std::cout << d << " -> " << dec2hex(d) << std::endl;
  }
  return 0;
}
