#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

bool is_vowel(char chr) {
  return (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u');
}

std::pair<std::string, std::string> split_at_vowel(const std::string &word) {
  std::string before_sep, after_sep;
  bool found_sep{false};

  for (size_t i{0}; i < word.length(); ++i) {
    if (is_vowel(word[i])) {
      found_sep = true;
      after_sep += word[i];
      continue;
    }
    if (found_sep)
      after_sep += word[i];
    else
      before_sep += word[i];
  }

  return {before_sep, after_sep};
}

int main() {
  std::string line;
  std::vector<std::string> words;
  std::getline(std::cin, line);

  std::string buffer;
  for (char chr : line) {
    if (chr == ' ') {
      words.emplace_back(buffer);
      buffer.clear();
    } else {
      buffer += chr;
    }
  }

  words.push_back(buffer);

  std::string first_word{words.front()}, last_word{words.back()};
  auto first_word_splited{split_at_vowel(first_word)};
  auto last_word_splited{split_at_vowel(last_word)};

  std::swap(first_word_splited.second, last_word_splited.second);

  words.front() = first_word_splited.first + first_word_splited.second;
  words.back() = last_word_splited.first + last_word_splited.second;

  bool printed{false};
  for (const std::string &word : words) {
    if (printed)
      std::cout << " ";
    else
      printed = true;

    std::cout << word;
  }
}
