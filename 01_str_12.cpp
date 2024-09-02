#include <array>
#include <charconv>
#include <iostream>
#include <string>

std::tuple<int, int, int> get_date(const std::string &short_date) {
  int date, month, year;
  std::from_chars(short_date.c_str(), short_date.c_str() + 2, date);
  std::from_chars(short_date.c_str() + 3, short_date.c_str() + 5, month);
  std::from_chars(short_date.c_str() + 6, short_date.c_str() + 10, year);
  return {date, month, year};
}

constexpr std::array<char[4], 12> months{{"JAN", "FEB", "MAR", "APR", "MAY",
                                          "JUN", "JUL", "AUG", "SEP", "OCT",
                                          "NOV", "DEC"}};

int main() {
  std::string short_date;
  std::cin >> short_date;
  const auto [date, month, year]{get_date(short_date)};
  std::cout << months[month - 1] << " " << date << ", " << year << std::endl;
}
