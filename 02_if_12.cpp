#include <iostream>

int main() {
  double score{0};
  char grade{'F'};

  std::cin >> score;

  if (score >= 80)
    grade = 'A';
  else if (score >= 70)
    grade = 'B';
  else if (score >= 60)
    grade = 'C';
  else if (score >= 50)
    grade = 'D';

  std::cout << grade << std::endl;
}
