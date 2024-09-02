#include <cctype>
#include <iostream>
#include <set>
#include <string>

void clean_and_insert(std::string &str, std::multiset<char> &multiset) {
  for (char chr : str) {
    if (std::isalpha(chr))
      multiset.insert(std::tolower(chr));
  }
}

int main() {
  std::string first_string, second_string;

  std::getline(std::cin, first_string);
  std::getline(std::cin, second_string);

  std::multiset<char> first_set, second_set;

  clean_and_insert(first_string, first_set);
  clean_and_insert(second_string, second_set);

  if (first_set == second_set)
    std::cout << "YES";
  else
    std::cout << "NO";
}
