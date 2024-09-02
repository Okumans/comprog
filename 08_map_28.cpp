#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::pair<std::string, std::string> split(const std::string &original,
                                          const std::string &sep) {
  size_t sep_pos{original.find(sep)};
  assert(sep_pos != std::string::npos);

  return {original.substr(0, sep_pos), original.substr(sep_pos + sep.length())};
}

int main() {
  int numbers;
  std::string buffer, line_buffer;
  std::map<std::string, std::vector<std::string>> song_map;

  std::cin >> numbers;
  std::cin.ignore();

  for (int i{0}; i < numbers; ++i) {
    std::getline(std::cin, buffer);
    auto splited{split(buffer, ", ")};

    song_map[splited.first].push_back(splited.second);
  }

  std::getline(std::cin, line_buffer);
  buffer.clear();

  std::vector<std::string> target_songs;

  for (int i{0}; i < line_buffer.length(); ++i) {
    if (line_buffer[i] == ',') {
      target_songs.push_back(buffer);
      buffer.clear();
      i++;
    }

    else {
      buffer.push_back(line_buffer[i]);
    }
  }

  if (buffer.size())
    target_songs.push_back(buffer);

  for (const std::string &song_name : target_songs) {
    std::cout << song_name << " -> ";

    bool printed{false};
    for (const std::string &author : song_map[song_name]) {
      (printed && std::cout << ", ") || (printed = true);
      std::cout << author;
    }

    if (!printed)
      std::cout << "Not found";

    std::cout << "\n";
  }
}
