#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

char to_real_info(bool a, bool b, bool c, bool d) {
  int value{(1 * d) + (2 * c) + (4 * b) + (8 * a)};
  switch (value) {
  case 10:
    return '-';
  case 11:
    return ',';
  default:
    return static_cast<char>('0' + value);
  }
}

std::array<bool, 4> from_real_info(char info) {
  if (info == ',')
    return {1, 0, 1, 1};
  if (info == '-')
    return {1, 0, 1, 0};

  int n{info - '0'};
  std::array<bool, 4> bitArray;
  std::bitset<4> bits(n);

  for (size_t i{0}; i < 4; i++) {
    bitArray[3 - i] = bits[i];
  }

  return bitArray;
}

size_t case_mask(size_t begin, const std::string &content,
                 std::array<bool, 4> mask) {
  size_t ind{begin};
  for (int count{0}; count < 4; ind = (ind + 1) % content.length(), count++) {
    if (!std::isalpha(content[ind])) {
      std::cout << content[ind];
      count--;
    } else if (mask[count])
      std::cout << static_cast<char>(std::tolower(content[ind]));
    else
      std::cout << static_cast<char>(std::toupper(content[ind]));
  }

  return ind;
}

void decode(const std::string &decoded_message) {
  char buffer[4];

  // lpi : last printed index
  for (size_t ind{0}, buff_ind{0}, lpi{0}; ind < decoded_message.size();
       ind++) {
    if (std::isalpha(decoded_message[ind]))
      buffer[buff_ind++ % 4] = decoded_message[ind];

    if (lpi != buff_ind && (lpi = buff_ind) % 4 == 0)
      std::cout << to_real_info(
          std::islower(buffer[0]), std::islower(buffer[1]),
          std::islower(buffer[2]), std::islower(buffer[3]));
  }
  std::cout << "\n";
}

void encode(const std::string &original_message, const std::string &rawkey) {
  for (size_t ind{0}, count{0}; count < original_message.size(); count++) {
    ind = case_mask(ind, rawkey, from_real_info(original_message[count]));
  }
  std::cout << "\n";
}

int main() {
  std::string key;
  std::getline(std::cin, key);

  char mode;
  while (std::cin >> mode) {
    std::string input_message;
    std::cin.ignore();
    std::getline(std::cin, input_message);

    if (mode == 'E')
      encode(input_message, key);
    else if (mode == 'D')
      decode(input_message);
  }
}
