#include <iostream>
#include <ostream>

struct Contestant {
  long long id;
  double gpax;
  char comprog;
  char cal1;
  char cal2;

  bool operator<(const Contestant &other) const {
    if (gpax != other.gpax)
      return gpax < other.gpax;

    if (cal1 != other.cal1)
      return cal1 > other.cal1;

    if (cal2 != other.cal2)
      return cal2 > other.cal2;

    return false;
  }

  bool value_equal(const Contestant &other) const {
    return (gpax == other.gpax && comprog == other.comprog &&
            cal1 == other.cal1 && cal2 == other.cal2);
  }
};

enum class Status { Person1, Person2, None, Both };

Status select_winner_contestant(const Contestant &per1,
                                const Contestant &per2) {

  bool succeed_1 =
      (per1.comprog == 'A' && per1.cal1 <= 'C' && per1.cal2 <= 'C');
  bool succeed_2 =
      (per2.comprog == 'A' && per2.cal1 <= 'C' && per2.cal2 <= 'C');

  if (!succeed_1 && !succeed_2)
    return Status::None;

  if (succeed_1 && !succeed_2)
    return Status::Person1;

  if (succeed_2 && !succeed_1)
    return Status::Person2;

  if (per1.value_equal(per2))
    return Status::Both;

  if (per1 < per2)
    return Status::Person2;

  return Status::Person1;
}

int main() {
  Contestant per1, per2;

  std::cin >> per1.id >> per1.gpax >> per1.comprog >> per1.cal1 >> per1.cal2;
  std::cin >> per2.id >> per2.gpax >> per2.comprog >> per2.cal1 >> per2.cal2;

  switch (select_winner_contestant(per1, per2)) {
  case Status::Person1:
    std::cout << per1.id;
    break;

  case Status::Person2:
    std::cout << per2.id;
    break;

  case Status::None:
    std::cout << "None";
    break;

  case Status::Both:
    std::cout << "Both";
    break;
  }

  std::cout << std::endl;
}
