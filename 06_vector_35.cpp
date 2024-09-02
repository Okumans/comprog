#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

const std::unordered_map<std::string, int> value_indicator_digits{
    {"soon", 0}, {"et", 1}, {"yi", 2},  {"neung", 1}, {"song", 2}, {"sam", 3},
    {"si", 4},   {"ha", 5}, {"hok", 6}, {"chet", 7},  {"paet", 8}, {"kao", 9}};

const std::unordered_map<std::string, int> digit_indicator_digits{
    {"sip", 10},      {"roi", 100},      {"phan", 1'000},
    {"muen", 10'000}, {"saen", 100'000}, {"lan", 1'000'000}};

int convert_from_thai(std::string str_number) {
  std::istringstream iss;
  iss.str(str_number);

  std::string buffer;

  int total_sum{0};
  int buffer_sum{0};

  while (iss >> buffer) {
    if (value_indicator_digits.find(buffer) != value_indicator_digits.end()) {
      if (buffer_sum == 0)
        buffer_sum = value_indicator_digits.at(buffer);
      else
        buffer_sum += value_indicator_digits.at(buffer);
    }

    else {
      if (buffer_sum == 0)
        buffer_sum = digit_indicator_digits.at(buffer);
      else {
        buffer_sum *= digit_indicator_digits.at(buffer);
        total_sum += buffer_sum;
        buffer_sum = 0;
      }
    }
  }

  total_sum += buffer_sum;
  return total_sum;
}

int main() {
  std::string line;
  while (std::getline(std::cin, line) && line != "q") {
    std::cout << convert_from_thai(line) << "\n";
  }
}
