#include <cctype>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

const std::unordered_map<int, std::vector<char>> num_mapping{
    {0, {' '}},           {1, {}},
    {2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}},
    {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}},
    {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}},
    {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}}};

std::unordered_map<char, std::string> text_mapping;

static void generate_text_mapping() {
  for (const auto &num_pair : num_mapping) {
    for (int ind{0}; ind < num_pair.second.size(); ++ind) {
      text_mapping[num_pair.second[ind]] =
          std::string(ind + 1, static_cast<char>('0' + num_pair.first));
    }
  }
}

std::string T2K(const std::string &content) {
  std::string result;

  for (char character : content) {
    if (character != ' ' && !std::isalpha(character))
      continue;

    result += text_mapping[std::tolower(character)];
    result += ' ';
  }

  if (result.size())
    result.pop_back();

  return result;
}

std::string K2T(const std::string &content) {
  std::istringstream iss(content);
  std::string result, buffer;

  while (iss >> buffer) {
    const auto &num_arr{num_mapping.at(buffer[0] - '0')};
    result += num_arr[(static_cast<int>(buffer.size()) - 1) % num_arr.size()];
  }

  return result;
}

int main() {

  generate_text_mapping();
  std::string command_buffer, line_buffer;

  while (std::cin >> command_buffer) {
    std::cin.ignore();
    std::getline(std::cin, line_buffer);

    if (command_buffer == "T2K")
      std::cout << ">> " << T2K(line_buffer) << "\n";
    else
      std::cout << ">> " << K2T(line_buffer) << "\n";
  }
}
