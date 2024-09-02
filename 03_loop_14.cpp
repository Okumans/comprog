#include <iostream>
#include <string>

int main() {
  std::string answers, user_answer;
  std::getline(std::cin, answers);
  std::getline(std::cin, user_answer);

  if (answers.length() != user_answer.length()) {
    std::cout << "Incomplete answer" << std::endl;
    return 0;
  }

  int score{0};
  for (size_t ind{0}; ind < answers.length(); ind++)
    score += (answers[ind] == user_answer[ind]);

  std::cout << score << std::endl;
}
