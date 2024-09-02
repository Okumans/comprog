#include <iostream>
#include <set>
#include <sstream>
#include <unordered_map>
#include <vector>

int main() {
  std::string line_buffer, buffer;
  std::istringstream iss;
  std::unordered_map<std::string, std::set<std::string>> from_to;

  while (std::getline(std::cin, line_buffer)) {
    std::vector<std::string> args;
    iss.str(line_buffer);

    while (iss >> buffer) {
      args.push_back(buffer);
    }

    iss.clear();

    if (args.size() == 2) {
      std::string from{args[0]}, to{args[1]};

      from_to[from].insert(to);
      from_to[to].insert(from);
    }

    else {
      std::string from{args[0]};

      std::vector<std::string> station_to_be_inserted;

      for (const std::string &first_station : from_to[from]) {
        for (const std::string &second_station : from_to[first_station]) {
          station_to_be_inserted.push_back(second_station);
        }
      }

      for (const std::string &next_station : station_to_be_inserted) {
        from_to[from].insert(next_station);
      }

      from_to[from].insert(from);

      for (const std::string &station : from_to[from]) {
        std::cout << station << "\n";
      }

      break;
    }
  }
}
