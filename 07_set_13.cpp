#include <iostream>
#include <set>

int main() {

  std::set<std::string> win_teams, lose_teams;
  std::string win_team, lose_team;

  while (std::cin >> win_team >> lose_team) {
    lose_teams.insert(lose_team);

    if (lose_teams.find(win_team) == lose_teams.end())
      win_teams.insert(win_team);

    win_teams.erase(lose_team);
  }

  if (win_teams.empty())
    std::cout << "None";

  else {
    bool printed{false};
    for (std::string win_team : win_teams) {
      (printed && std::cout << " ") || (printed = true);
      std::cout << win_team;
    }
  }
}
