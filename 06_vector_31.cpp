#include <array>
#include <iostream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

std::array<std::array<int, 5>, 5> otable;

class BingoTable {
private:
  std::array<std::array<int, 5>, 5> m_table;
  std::vector<std::string> m_tries;

  int col_to_number(char col) const {
    switch (col) {
    case 'B':
      return 0;
    case 'I':
      return 1;
    case 'N':
      return 2;
    case 'G':
      return 3;
    case 'O':
      return 4;
    default:
      throw std::runtime_error("Col is'nt valid.");
    }
  }

  char number_to_col(int col) const {
    switch (col) {
    case 0:
      return 'B';
    case 1:
      return 'I';
    case 2:
      return 'N';
    case 3:
      return 'G';
    case 4:
      return 'O';
    default:
      throw std::runtime_error("Col is'nt valid.");
    }
  }
  void set_zero(char col, const std::string &raw_value) {
    int value{std::stoi(raw_value)};
    int col_num{col_to_number(col)};

    for (int i{0}; i < 5; ++i) {
      if (m_table[i][col_num] == value) {
        m_table[i][col_num] = 0;
        return;
      }
    }
  }

public:
  std::vector<std::string> get_history() const { return m_tries; }

  std::vector<std::vector<std::pair<char, int>>> check() const {
    std::vector<std::vector<std::pair<char, int>>> answers;
    // check for horizontal and vertical bingo

    std::vector<std::vector<std::pair<char, int>>> answers_h;
    std::vector<std::vector<std::pair<char, int>>> answers_v;

    for (int i{0}; i < 5; ++i) {
      std::vector<std::pair<char, int>> sum_h, sum_v;
      for (int j{0}; j < 5; ++j) {
        if (!m_table[i][j])
          sum_h.emplace_back(number_to_col(j), otable[i][j]);
        if (!m_table[j][i])
          sum_v.emplace_back(number_to_col(i), otable[j][i]);
      }

      if (sum_h.size() == 5)
        answers_h.push_back(sum_h);

      if (sum_v.size() == 5)
        answers_v.push_back(sum_v);
    }

    answers.insert(answers.end(), answers_h.begin(), answers_h.end());
    answers.insert(answers.end(), answers_v.begin(), answers_v.end());

    // check for cross_l_r and cross_r_l
    std::vector<std::pair<char, int>> sum_l_r, sum_r_l;
    for (int l_r{0}, r_l_x{0}, r_l_y{4}; l_r < 5; ++l_r, --r_l_y, ++r_l_x) {
      if (!m_table[l_r][l_r])
        sum_l_r.emplace_back(number_to_col(l_r), otable[l_r][l_r]);

      if (!m_table[r_l_y][r_l_x])
        sum_r_l.emplace_back(number_to_col(r_l_x), otable[r_l_y][r_l_x]);
    }

    if (sum_r_l.size() == 5)
      answers.push_back(sum_r_l);

    if (sum_l_r.size() == 5)
      answers.push_back(sum_l_r);

    return answers;
  }

  bool add(const std::string &position) {
    m_tries.emplace_back(position);
    set_zero(position[0], position.substr(1));
    return check().size();
  }

public:
  BingoTable(std::array<std::array<int, 5>, 5> table) : m_table{table} {}
};

int main() {
  int buffer;
  char buffer0;

  for (int i{0}; i < 5; ++i) {
    std::cin >> buffer0;
  }

  for (int i{0}; i < 5; ++i) {
    for (int j{0}; j < 5; ++j) {
      if (i == 2 && j == 2) {
        std::cin >> buffer0;
        otable[i][j] = 0;
        continue;
      }

      std::cin >> buffer;
      otable[i][j] = buffer;
    }
  }

  std::string position_buffer;
  BingoTable bingo(otable);

  while (std::cin >> position_buffer) {
    if (bingo.add(position_buffer)) {
      auto history{bingo.get_history()};

      std::cout << history.size() << "\n";

      for (auto set : bingo.check()) {
        bool printed{false};
        for (auto &elem : set) {
          if (elem.first == 'N' && elem.second == 0)
            continue;
          (printed && std::cout << ", ") || (printed = true);
          std::cout << elem.first << elem.second;
        }
        std::cout << "\n";
      }
      return 0;
    }
  }
}
