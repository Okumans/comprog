#include <cmath>
#include <iostream>
#include <unordered_map>

struct Money {
  std::string country_name;
  double baht_value{0};
  const std::unordered_map<std::string, double> &country_exchange_values;

  double get_value() const {
    return baht_value / country_exchange_values.at(country_name);
  }

  void from_country(const std::string country_name, double value) {
    this->country_name = country_name;
    this->baht_value = country_exchange_values.at(country_name) * value;
  }

  void convert_to_country(const std::string country_name) {
    this->country_name = country_name;
    baht_value =
        country_exchange_values.at(country_name) *
        std::floor(baht_value / country_exchange_values.at(country_name));
  }

  Money(const std::string &country_name,
        const std::unordered_map<std::string, double> &country_exchange_values,
        double country_value)
      : country_name{country_name},
        country_exchange_values{country_exchange_values} {
    from_country(country_name, country_value);
  }
};

int main() {
  int numbers;

  std::string country_buffer;
  double country_exchange_value_buffer;

  std::unordered_map<std::string, double> country_exchange_values{{"THB", 1}};

  std::cin >> numbers;
  for (int i{0}; i < numbers; ++i) {
    std::cin >> country_buffer >> country_exchange_value_buffer;
    country_exchange_values[country_buffer] = country_exchange_value_buffer;
  }

  std::cin >> country_exchange_value_buffer;
  std::cin >> country_buffer;

  Money exchange_money(country_buffer, country_exchange_values,
                       country_exchange_value_buffer);

  std::cout << static_cast<int>(exchange_money.get_value()) << " "
            << exchange_money.country_name;
  while (std::cin >> country_buffer) {
    std::cout << " -> ";
    exchange_money.convert_to_country(country_buffer);
    std::cout << static_cast<int>(exchange_money.get_value()) << " "
              << exchange_money.country_name;
  }

  std::cout << "\n";
}
