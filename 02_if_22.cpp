#include <array>
#include <iostream>

const std::array<int, 13> months_days{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

const std::array<int, 13> generate_qs_table() {
  std::array<int, 13> temp;
  temp[0] = months_days[0];

  for (int i{1}; i < 13; ++i)
    temp[i] = temp[i - 1] + months_days[i];

  return temp;
}

bool is_leapyear(int year) {
  return ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0));
}

int main() {
  const std::array<int, 13> qs_months_days{generate_qs_table()};
  int day, month, year;
  std::cin >> day >> month >> year;
  std::cout << qs_months_days[month - 1] +
                   (month > 2 && is_leapyear(year - 543)) + day
            << std::endl;
}
