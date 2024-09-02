#include <algorithm>
#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>
#include <ostream>
#include <sys/types.h>
#include <vector>

enum class Grade : int8_t {
  F = 0,
  D = 1,
  D_plus = 2,
  C = 3,
  C_plus = 4,
  B = 5,
  B_plus = 6,
  A = 7
};

std::ostream &operator<<(std::ostream &os, const Grade &grade) {
  switch (grade) {
  case Grade::A:
    os << "A";
    break;
  case Grade::B_plus:
    os << "B+";
    break;
  case Grade::B:
    os << "B";
    break;
  case Grade::C_plus:
    os << "C+";
    break;
  case Grade::C:
    os << "C";
    break;
  case Grade::D_plus:
    os << "D+";
    break;
  case Grade::D:
    os << "D";
    break;
  case Grade::F:
    os << "F";
    break;
  }
  return os;
}

Grade parse_grade(const std::string &string_grade) {
  if (string_grade == "A")
    return Grade::A;
  if (string_grade == "B+")
    return Grade::B_plus;
  if (string_grade == "B")
    return Grade::B;
  if (string_grade == "C+")
    return Grade::C_plus;
  if (string_grade == "C")
    return Grade::C;
  if (string_grade == "D+")
    return Grade::D_plus;
  if (string_grade == "D")
    return Grade::D;
  return Grade::F;
}

class Student {
  std::string m_student_id;
  Grade m_grade;

public:
  void increase() {
    m_grade = static_cast<Grade>(std::min<int8_t>(
        static_cast<int8_t>(Grade::A), static_cast<int8_t>(m_grade) + 1));
  }

  void decrease() {
    m_grade = static_cast<Grade>(std::max<int8_t>(
        static_cast<int8_t>(Grade::F), static_cast<int8_t>(m_grade) - 1));
  }

  bool operator>(const Student &other) const {
    return (static_cast<int8_t>(m_grade) > static_cast<int8_t>(other.m_grade));
  }

  bool is_same_id(const std::string other_student_id) const {
    return m_student_id == other_student_id;
  }

  Student(const std::string &student_id, const std::string &grade)
      : m_student_id{student_id}, m_grade{parse_grade(grade)} {}

  Student(std::string &&student_id, std::string &&grade)
      : m_student_id{student_id}, m_grade{parse_grade(grade)} {}

  friend std::ostream &operator<<(std::ostream &os, const Student &student) {
    os << student.m_student_id << " " << student.m_grade;
    return os;
  }
};

int main() {
  uint32_t numbers;
  std::vector<Student> students;
  std::cin >> numbers;

  std::string grade_buffer, student_id_buffer;

  for (uint32_t i{0}; i < numbers; ++i) {
    std::cin >> student_id_buffer >> grade_buffer;
    students.emplace_back(std::move(student_id_buffer),
                          std::move(grade_buffer));
  }

  std::string change_buffer;
  while (std::cin >> change_buffer) {
    char charge{change_buffer.back()};
    change_buffer.pop_back(); // remove charge

    auto target_student{std::find_if(students.begin(), students.end(),
                                     [&change_buffer](const Student &student) {
                                       return student.is_same_id(change_buffer);
                                     })};

    if (charge == '+')
      target_student->increase();
    else
      target_student->decrease();
  }

  std::sort(students.begin(), students.end(), std::greater<Student>());
  for (const auto &student : students) {
    std::cout << student << "\n";
  }
}
