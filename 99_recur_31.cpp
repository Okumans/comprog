#include <iostream>
#include <map>
#include <set>
#include <string>

std::set<std::string> permunations;
int n;

void play(std::map<char, int> &chars, std::string &result) {
  if (n == result.length()) {
    permunations.insert(result);
    return;
  }

  for (const auto &char_pair : chars) {
    if (!char_pair.second)
      continue;

    chars[char_pair.first]--;
    result.push_back(char_pair.first);

    play(chars, result);

    chars[char_pair.first]++;
    result.pop_back();
  }
}

int main() {
  std::string buffer;
  std::cin >> buffer;

  n = buffer.length();

  std::map<char, int> chars;
  for (char chr : buffer) {
    chars[chr]++;
  }

  std::string result;
  play(chars, result);

  bool printed{false};
  for (const std::string &permunation : permunations) {
    (printed && std::cout << " ") || (printed = true);
    std::cout << permunation;
  }
  std::cout << "\n";
}
