
#include <array>
#include <ios>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using AlphaArrayMap = std::array<int, 26>;

struct ArrayHash {
  size_t operator()(const AlphaArrayMap &arr) const {
    size_t hash = 0;
    for (int c : arr) {
      hash = hash * 31 + c;
    }
    return hash;
  }
};

std::unordered_map<AlphaArrayMap, int, ArrayHash> counts;
std::vector<std::string> buckets;
int bucket_numbers;
int get_numbers;

struct ResultSorting {
  AlphaArrayMap comb;
  int amount;

  bool operator>(const ResultSorting &other) const {
    return (amount == other.amount) ? comb < other.comb : amount < other.amount;
  }

  ResultSorting(std::pair<AlphaArrayMap, int> &&pair)
      : comb{std::move(pair.first)}, amount{pair.second} {}
};

void get_combinations(AlphaArrayMap &result, int current_bucket_number) {
  if (current_bucket_number >= bucket_numbers) {
    counts[result]++;
    return;
  }

  for (char bucket_value : buckets[current_bucket_number]) {
    result[bucket_value - 'A']++;
    get_combinations(result, current_bucket_number + 1);
    result[bucket_value - 'A']--;
  }
}

int main() {
  std::string bucket_buffer;
  AlphaArrayMap letter_map_count = {0};

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> bucket_numbers;

  buckets.reserve(bucket_numbers);
  for (int i{0}; i < bucket_numbers; ++i) {
    std::cin >> bucket_buffer;
    buckets.push_back(std::move(bucket_buffer));
  }

  std::cin >> get_numbers;
  counts.reserve(get_numbers);

  get_combinations(letter_map_count, 0);
  std::priority_queue<ResultSorting, std::vector<ResultSorting>, std::greater<>>
      result;

  for (auto &&pair_count : counts) {
    result.emplace(std::move(pair_count));
  }

  int counter{0};
  std::string output;
  output.reserve(50 * get_numbers);

  while (!result.empty() && counter < get_numbers) {
    output.clear();

    const auto &top = result.top();
    for (int i{0}; i < 26; ++i) {
      if (top.comb[i] > 0) {
        output.append(top.comb[i], static_cast<char>('A' + i));
      }
    }

    output.push_back('\n');
    std::cout << output;
    result.pop();

    counter++;
  }
}
