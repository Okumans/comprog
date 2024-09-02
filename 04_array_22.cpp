#include <iostream>
#include <string>

void cut_cards(std::string *cards, unsigned int size) {
  unsigned int first_pile_p{0}, second_pile_p{size / 2};
  for (unsigned int i{0}; i < size / 2; ++i)
    std::swap(cards[first_pile_p++], cards[second_pile_p++]);
}

void swap_cards(std::string *cards, unsigned int size) {
  unsigned int first_pile_p{0}, second_pile_p{size / 2};
  std::string *buffer{new std::string[size]};

  for (unsigned int i{0}, buffer_i{0}; i < size; ++i) {
    if (i % 2 == 0)
      std::swap(cards[first_pile_p++], buffer[buffer_i++]);
    else
      std::swap(cards[second_pile_p++], buffer[buffer_i++]);
  }

  for (int i{0}; i < size; ++i) {
    std::swap(cards[i], buffer[i]);
  }

  delete[] buffer;
}

int main() {
  unsigned int size;
  std::string cards[55], commands;

  std::cin >> size;

  for (unsigned int i{0}; i < size; i++)
    std::cin >> cards[i];

  std::cin.ignore();
  std::getline(std::cin, commands);

  for (char chr : commands) {
    if (chr == 'C')
      cut_cards(cards, size);
    else if (chr == 'S')
      swap_cards(cards, size);
  }

  for (unsigned int i{0}; i < size; i++)
    std::cout << (i == 0 ? "" : " ") << cards[i];
  std::cout << std::endl;
}
