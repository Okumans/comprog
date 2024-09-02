#include <iostream>
#include <unordered_map>

int main() {
  int numbers;
  std::unordered_map<std::string, std::string> name_map;
  std::string firstname, lastname, telenumber, buffer;

  std::cin >> numbers;
  for (int i{0}; i < numbers; ++i) {
    std::cin >> firstname >> lastname >> telenumber;
    std::string realname{firstname + " " + lastname};

    name_map[realname] = telenumber;
    name_map[telenumber] = realname;
  }

  std::cin >> numbers;
  std::cin.ignore();
  for (int i{0}; i < numbers; ++i) {
    std::getline(std::cin, buffer);
    if (name_map.find(buffer) != name_map.end())
      std::cout << buffer << " --> " << name_map[buffer] << std::endl;
    else
      std::cout << buffer << " --> Not found" << std::endl;
  }
}
