#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Timer {
public:
  void add_time(int seconds) { this->seconds += seconds; }

  static int parse_str(const std::string &str_time) {
    int minutes{std::stoi(str_time.substr(0, str_time.find(':')))};
    int seconds{std::stoi(str_time.substr(str_time.find(':') + 1))};

    return minutes * 60 + seconds;
  }

  int get_raw_time() const { return seconds; }

  std::string get_time() const {
    return std::to_string(seconds / 60) + ":" + std::to_string(seconds % 60);
  }

  bool operator<(const Timer &other) const { return seconds < other.seconds; }

private:
  int seconds;
};

void sort(const std::unordered_map<std::string, Timer> &mapp) {
  std::vector<std::pair<std::string, Timer>> temp;

  for (auto &it : mapp) {
    temp.push_back(it);
  }

  std::sort(temp.begin(), temp.end(),
            [](const std::pair<std::string, Timer> &a,
               const std::pair<std::string, Timer> &b) {
              return a.second.get_raw_time() > b.second.get_raw_time();
            });

  for (int i{0}; i < std::min(3, static_cast<int>(temp.size())); ++i) {
    std::cout << temp[i].first << " --> " << temp[i].second.get_time() << "\n";
  }
}

int main() {
  std::string buffer, genre, time;
  std::unordered_map<std::string, Timer> time_per_genre;

  while (std::cin >> buffer >> buffer >> genre >> time) {
    time_per_genre[genre].add_time(Timer::parse_str(time));
  }

  sort(time_per_genre);
}
