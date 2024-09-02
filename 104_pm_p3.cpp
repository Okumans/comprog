#include <bits/stdc++.h>

struct Bid {
  int order;
  int bid_amount;
  std::string bidder;

  bool operator<(const Bid &other) const {
    return (bid_amount == other.bid_amount) ? (order < other.order)
                                            : (bid_amount > other.bid_amount);
  }
};

std::map<std::string, std::map<std::string, Bid>> biddings;
std::map<std::string, int> money_spend_by_bidders;
std::map<std::string, std::set<std::string>> goods_bidded_by_bidders;

int main() {
  int bid_numbers;

  std::string bidder_name, bid_name;
  int bid_amount;
  char operation;

  std::cin >> bid_numbers;
  for (int i{0}; i < bid_numbers; ++i) {
    std::cin >> operation >> bidder_name >> bid_name;

    if (operation == 'B') {
      std::cin >> bid_amount;
      goods_bidded_by_bidders[bidder_name];
      biddings[bid_name][bidder_name] = {i, bid_amount, bidder_name};
    } else {
      biddings[bid_name].erase(bidder_name);
    }
  }

  std::map<std::string, std::set<Bid>> arranged_biddings;
  for (const auto &_bid_name_pair : biddings) {
    for (const auto &_bidder_name_pair : _bid_name_pair.second) {
      arranged_biddings[_bid_name_pair.first].insert(_bidder_name_pair.second);
    }
  }

  for (const auto &_bid_name_pair : arranged_biddings) {
    for (const auto &_bid : _bid_name_pair.second) {
      goods_bidded_by_bidders[_bid.bidder].insert(_bid_name_pair.first);
      money_spend_by_bidders[_bid.bidder] += _bid.bid_amount;
      break;
    }
  }

  for (const auto &key_value : goods_bidded_by_bidders) {
    std::cout << key_value.first << ": ";
    std::cout << "$" << money_spend_by_bidders[key_value.first];

    if (key_value.second.empty()) {
      std::cout << "\n";
      continue;
    }

    std::cout << " ->";
    for (const auto &bid_namee : key_value.second) {
      std::cout << " " << bid_namee;
    }
    std::cout << "\n";
  }
}
