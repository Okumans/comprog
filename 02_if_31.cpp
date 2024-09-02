#include <array>
#include <cmath>
#include <iostream>

const std::array<int, 13> months_days{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

const std::array<int, 13> generate_qs_table() {
  std::array<int, 13> temp = {};
  temp[0] = months_days[0];

  for (int i{1}; i < 13; ++i)
    temp[i] = temp[i - 1] + months_days[i];

  return temp;
}

const std::array<int, 13> qs_months_days{generate_qs_table()};

bool is_leapyear(int year) {
  return ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0));
}

int since_start_of_year(int day, int month, int year) {
  return qs_months_days[month - 1] + (month > 2 && is_leapyear(year)) + day - 1;
}

int until_end_of_year(int day, int month, int year) {
  return (365 + is_leapyear(year)) - since_start_of_year(day, month, year);
}

inline int days_since_born(int bday, int bmonth, int byear, int nday,
                           int nmonth, int nyear) {
  int red_range{until_end_of_year(bday, bmonth, byear)};
  int blue_range{since_start_of_year(nday, nmonth, nyear)};
  int black_range{(nyear - byear - 1) * 365};

  return red_range + blue_range + black_range;
}

inline double calculate_biorhythm(int t, int denomerator) {
  return std::round(100 * std::sin((2 * M_PI * t) / denomerator)) / 100;
}

int main() {
  int bday, bmonth, byear;
  int nday, nmonth, nyear;

  std::cin >> bday >> bmonth >> byear;
  std::cin >> nday >> nmonth >> nyear;

  int t{days_since_born(bday, bmonth, byear - 543, nday, nmonth, nyear - 543)};
  std::cout << t << " " << calculate_biorhythm(t, 23) << " "
            << calculate_biorhythm(t, 28) << " " << calculate_biorhythm(t, 33)
            << std::endl;
}
