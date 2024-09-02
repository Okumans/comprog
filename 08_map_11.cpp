#include <iostream>
#include <unordered_map>

int main() {
  int numbers;
  std::unordered_map<std::string, std::string> name_map;
  std::string realname, nickname;

  std::cin >> numbers;
  for (int i{0}; i < numbers; ++i) {
    std::cin >> realname >> nickname;
    name_map[realname] = nickname;
    name_map[nickname] = realname;
  }

  std::cin >> numbers;
  for (int i{0}; i < numbers; ++i) {
    std::cin >> realname;
    if (name_map.find(realname) != name_map.end())
      std::cout << name_map[realname] << "\n";
    else
      std::cout << "Not found\n";
  }
}
