#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

template <typename T> unsigned int get_hash(const T &content) {
  unsigned int result_hash{1};
  for (size_t i{1}; i <= content.length(); ++i) {
    result_hash *= (i * content[i - 1] + content[i - 1]) * (content[i - 1] - i);
  }
  return result_hash % 499;
}

int main() {
  int taxs_amount, taxs[500];

  std::istringstream iss;

  std::cin >> taxs_amount;

  for (int i{0}; i < taxs_amount; i++) {
    std::string country;

    std::cin >> country;
    std::cin >> taxs[get_hash(country)];
  }

  std::string airport_seq, word;
  unsigned int last_visited_country_hash, total_tax{0};

  std::cin.ignore();
  std::getline(std::cin, airport_seq);

  iss.str(airport_seq);

  iss >> word;
  last_visited_country_hash = get_hash(std::string_view(word.c_str() + 4, 2));

  while (iss >> word) {
    unsigned int curr_country_hash{
        get_hash(std::string_view(word.c_str() + 4, 2))};
    if (curr_country_hash != last_visited_country_hash) {
      total_tax += taxs[curr_country_hash];
      last_visited_country_hash = curr_country_hash;
    }
  }

  std::cout << total_tax << std::endl;
}
