#include <array>
#include <iostream>
#include <sstream>
#include <utility>

// constexpr can be use. at later version like c++17/20

const int SEARCH_LIMIT{50000};
const int PRIMES_PREDICT_NUMBERS{5500};

const auto get_primes() {
  std::array<bool, SEARCH_LIMIT> sieve;
  sieve.fill(true);
  sieve[0] = sieve[1] = false;

  for (size_t i{2}; i < SEARCH_LIMIT; ++i) {
    if (sieve[i]) {
      for (size_t j{i * i}; j < SEARCH_LIMIT; j += i)
        sieve[j] = false;
    }
  }

  std::array<int, PRIMES_PREDICT_NUMBERS> primes;
  int n{0};
  for (size_t i{2}; i < SEARCH_LIMIT; i++) {
    if (sieve[i])
      primes[n++] = i;
  }

  return std::make_pair(primes, n);
}

int main() {
  const auto primes{get_primes()};
  bool is_now_undividable{false}, is_first{true};
  int num;

  std::cin >> num;

  std::stringstream buffer;
  while (!is_now_undividable) {
    is_now_undividable = true;
    for (int i{0}; i < primes.second; ++i) {
      if (num % primes.first[i] == 0) {
        buffer << primes.first[i] << "*";
        num /= primes.first[i];
        is_now_undividable = false;
        break;
      }
    }
  }

  if (num == 1) {
    buffer.seekp(-1, std::ios_base::end);
    buffer << "\n";
  }

  else {
    buffer << num << "\n";
  }

  std::cout << buffer.str();
}
