#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int main() {
  std::unordered_map<std::string, std::vector<std::string>> type_names;
  std::vector<std::string> type_orders;
  std::string name, type;

  while (std::cin >> name >> type) {
    type_names[type].push_back(name);
    type_orders.push_back(type);
  }

  std::unordered_set<std::string> showed;
  for (const auto &type_order : type_orders) {
    if (showed.find(type_order) != showed.end())
      continue;
    showed.insert(type_order);
    std::cout << type_order << ": ";
    bool printed{false};
    for (const std::string &elm : type_names[type_order]) {
      (printed && std::cout << " ") || (printed = true);
      std::cout << elm;
    }
    std::cout << "\n";
  }
}
