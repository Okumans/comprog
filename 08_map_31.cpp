#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

struct Student {
  long long student_number;
  double score;
  std::array<std::string, 5> orders;

  bool operator>(const Student &other) const { return score > other.score; }
};

int main() {
  std::unordered_map<std::string, int> classes;
  std::map<long long, std::string> student_class;
  std::vector<Student> students;
  int numbers;

  std::cin >> numbers;
  for (int i{0}; i < numbers; ++i) {
    std::string str_buffer;
    int num_buffer;

    std::cin >> str_buffer >> num_buffer;
    classes[str_buffer] = num_buffer;
  }

  std::cin >> numbers;
  for (int i{0}; i < numbers; ++i) {
    Student std_buffer;
    std::cin >> std_buffer.student_number >> std_buffer.score >>
        std_buffer.orders[0] >> std_buffer.orders[1] >> std_buffer.orders[2] >>
        std_buffer.orders[3];
    students.push_back(std_buffer);
  }

  std::sort(students.begin(), students.end(), std::greater<Student>());
  for (const Student &student : students) {
    for (const auto &class_ : student.orders) {
      if (classes[class_] != 0) {
        student_class[student.student_number] = class_;
        classes[class_]--;
        break;
      }
    }
  }

  for (auto pair_student : student_class) {
    std::cout << pair_student.first << " " << pair_student.second << "\n";
  }
}
