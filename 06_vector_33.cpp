#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct Party {
  std::string name;
  int mp_numbers;
  double mp_remainder;
  int score;

  bool operator>(const Party &other) const { return score > other.score; }
};

int main() {
  std::string string_buffer;
  int number_buffer;

  std::vector<Party> parties;
  int total_score{0};

  while (std::cin >> string_buffer && string_buffer != "END" &&
         std::cin >> number_buffer) {
    parties.push_back({string_buffer, 0, 0, number_buffer});
    total_score += number_buffer;
  }

  double score_per_man{total_score / 100.0};
  int total_mp_numbers{0};

  for (Party &party : parties) {
    party.mp_numbers = std::floor(party.score / score_per_man);
    party.mp_remainder = (party.score / score_per_man) - party.mp_numbers;

    total_mp_numbers += party.mp_numbers;
  }

  std::sort(parties.begin(), parties.end(), [](const Party &a, const Party &b) {
    return a.mp_remainder > b.mp_remainder;
  });

  for (int i{0}; i < 100 - total_mp_numbers; ++i) {
    ++parties[i].mp_numbers;
  }

  std::sort(parties.begin(), parties.end(), std::greater<Party>());

  for (Party &party : parties) {
    if (!party.mp_numbers)
      break;

    std::cout << party.name << " " << party.mp_numbers << " " << party.score
              << "\n";
  }
}
