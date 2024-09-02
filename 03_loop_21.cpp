#include <cctype>
#include <iostream>
#include <string>

enum class PasswordStatus { Strong, Weak, Invalid };

PasswordStatus getPasswordStatus(const std::string &password) {
  bool contain_upper{false}, contain_lower{false}, contain_number{false},
      contain_other{false};

  for (char chr : password) {
    contain_lower = std::islower(chr) || contain_lower;
    contain_upper = std::isupper(chr) || contain_upper;
    contain_number = std::isdigit(chr) || contain_number;
    contain_other = std::ispunct(chr) || contain_other;
  }

  if (password.length() >= 12 && contain_lower && contain_upper &&
      contain_number && contain_other)
    return PasswordStatus::Strong;

  else if (password.length() >= 8 && contain_lower && contain_upper &&
           contain_number)
    return PasswordStatus::Weak;

  return PasswordStatus::Invalid;
}

int main() {
  std::string password;
  while (std::cin >> password) {
    switch (getPasswordStatus(password)) {
    case PasswordStatus::Strong:
      std::cout << ">> strong" << std::endl;
      break;

    case PasswordStatus::Weak:
      std::cout << ">> weak" << std::endl;
      break;

    case PasswordStatus::Invalid:
      std::cout << ">> invalid" << std::endl;
      break;
    }
  }
}
