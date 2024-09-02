#include <cmath>
#include <cstdint>
#include <iostream>
#include <stack>

void add_number(std::string &base, const std::string &adder) {
  int32_t remainder{0};
  int32_t max_length{
      static_cast<int32_t>(std::max(base.length(), adder.length()))};

  std::stack<char> reversed_result;
  for (int32_t base_i{static_cast<int32_t>(base.length() - 1)},
       adder_i{static_cast<int32_t>(adder.length() - 1)}, i{0};
       i < max_length; ++i, --base_i, --adder_i) {

    int32_t base_char{base_i >= 0 ? base[base_i] - '0' : 0};
    int32_t adder_char{adder_i >= 0 ? adder[adder_i] - '0' : 0};

    int32_t local_result{base_char + adder_char + remainder};

    reversed_result.push(local_result % 10 + '0');
    remainder = local_result >= 10;
  }

  if (remainder)
    reversed_result.push('0' + remainder);

  base.clear();
  while (!reversed_result.empty()) {
    base += reversed_result.top();
    reversed_result.pop();
  }
}

int main() {
  std::string buffer, number{"0"};

  std::cin >> buffer;

  while (buffer != "END") {
    add_number(number, buffer);
    std::cin >> buffer;
  }

  std::cout << number;
}
