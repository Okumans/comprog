#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

int add_eng(char *two_digits, int amount) {
  auto div_result = std::div(two_digits[1] - 'A' + amount, 26);
  int _remainder = div_result.quot;
  int second_digit = div_result.rem;

  div_result = std::div(two_digits[0] - 'A' + _remainder, 26);
  int remainder = div_result.quot;
  int first_digit = div_result.rem;

  two_digits[0] = first_digit + 'A';
  two_digits[1] = second_digit + 'A';

  return remainder;
}

int add_single_digit(char *single_digit, int amount) {
  auto div_result = std::div(single_digit[0] - '0' + amount, 10);
  int remainder = div_result.quot;
  int digit = div_result.rem;
  single_digit[0] = digit + '0';

  return remainder;
}

int add_triple_digit(char *triple_digit, int amount) {
  return add_single_digit(
      triple_digit,
      add_single_digit(triple_digit + 1,
                       add_single_digit(triple_digit + 2, amount)));
}

int main() {
  char digits[8];
  int amount;

  std::scanf("%s", digits);
  std::scanf("%d", &amount);
  add_single_digit(digits,
                   add_eng(digits + 1, add_triple_digit(digits + 4, amount)));
  std::cout << digits;
}
