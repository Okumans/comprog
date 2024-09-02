#include <array>
#include <cmath>
#include <iostream>

template <size_t N>
/*constexpr*/ const std::array<long long, N> get_precomputed10N() {
  std::array<long long, N> arr{};
  for (size_t i{0}; i < N; ++i) {
    long long result{1};
    for (size_t j{0}; j < i; ++j) {
      result *= 10;
    }
    arr[i] = result;
  }
  return arr;
}

/*constexpr*/ const auto precomputed10N{get_precomputed10N<19>()};

int get_digit(long long number, size_t at) {
  return number % precomputed10N[at + 1] / precomputed10N[at];
}

// fastest way to get length of number
size_t get_length(long long number) {
  if (number < 0)
    number = -number; // Handle negative numbers
  return (number == 0)                        ? 1
         : (number < 10LL)                    ? 1
         : (number < 100LL)                   ? 2
         : (number < 1000LL)                  ? 3
         : (number < 10000LL)                 ? 4
         : (number < 100000LL)                ? 5
         : (number < 1000000LL)               ? 6
         : (number < 10000000LL)              ? 7
         : (number < 100000000LL)             ? 8
         : (number < 1000000000LL)            ? 9
         : (number < 10000000000LL)           ? 10
         : (number < 100000000000LL)          ? 11
         : (number < 1000000000000LL)         ? 12
         : (number < 10000000000000LL)        ? 13
         : (number < 100000000000000LL)       ? 14
         : (number < 1000000000000000LL)      ? 15
         : (number < 10000000000000000LL)     ? 16
         : (number < 100000000000000000LL)    ? 17
         : (number < 1000000000000000000LL)   ? 18
         : (number < 10000000000000000000ULL) ? 19
                                              : 20;
}

long long total_spread_digit(long long start, long long stop) {
  size_t start_l{get_length(start)};
  size_t stop_l{get_length(stop)};

  if (start == stop)
    return start_l;

  if (start_l == stop_l)
    return (stop - start + 1) * start_l;

  long long start_until_next_digit{(precomputed10N[start_l] - start) *
                                   static_cast<long long>(start_l)};
  long long stop_since_previous_digit{(stop % precomputed10N[stop_l - 1] + 1) *
                                      static_cast<long long>(stop_l)};
  long long between_start_l_stop_l{0};

  // sigma start_l+1 -> stop_l-1 (n*10^n)
  for (size_t n{start_l + 1}; n < stop_l; ++n)
    between_start_l_stop_l += (n * (precomputed10N[n] - precomputed10N[n - 1]));

  between_start_l_stop_l +=
      (static_cast<long long>(get_digit(stop, stop_l - 1)) - 1) *
      precomputed10N[stop_l - 1] * stop_l;

  return start_until_next_digit + between_start_l_stop_l +
         stop_since_previous_digit;
}

int main() {
  long long start, stop;
  std::cin >> start >> stop;
  std::cout << total_spread_digit(start, stop) << std::endl;
}
