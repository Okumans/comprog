#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

char end_sequence[6] = {2, 3, 4, 5, 6, 7};
const std::unordered_map<char, int> points_by_char{
    {'R', 1}, {'Y', 2}, {'G', 3}, {'N', 4}, {'B', 5}, {'P', 6}, {'K', 7}};

int calculate_score(const std::string &str_sequence) {
  std::vector<int> sequence(str_sequence.length() / 2 + 1);
  for (int si{0}, i{0}; si < str_sequence.length(); si += 2, ++i)
    sequence[i] = points_by_char.at(str_sequence[si]);

  if (sequence[0] != 1)
    return -1;

  if (sequence.size() == 1)
    return 1;

  auto rit_last_R{std::find(sequence.rbegin(), sequence.rend(), 1)};
  if (rit_last_R == sequence.rend())
    return -1;

  auto it_last_R{(rit_last_R + 1).base()};

  if (it_last_R != std::prev(sequence.end())) {
    if (it_last_R - sequence.begin() > sequence.size() - 2)
      return -1;

    int pos{0};
    for (auto it{it_last_R + 2}; it != sequence.end(); ++it, ++pos) {
      if (end_sequence[pos] != *it)
        return -1;
    }
  }

  for (auto it{std::next(sequence.begin())}; it != std::next(it_last_R); it++) {
    if (*it == 1 && *std::prev(it) == 1)
      return -1;
    if (*it != 1 && *std::prev(it) != 1)
      return -1;
  }

  return std::accumulate(sequence.begin(), sequence.end(), 0);
}

int main() {
  int q;
  std::cin >> q;
  std::cin.ignore();
  while (q--) {
    std::string sequence;
    std::getline(std::cin, sequence);
    int score{calculate_score(sequence)};
    if (score == -1)
      std::cout << "WRONG_INPUT" << std::endl;
    else
      std::cout << score << std::endl;
  }
}
