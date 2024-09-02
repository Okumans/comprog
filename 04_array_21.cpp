#include <iomanip>
#include <iostream>

double fscf(int *seqs, unsigned int size, unsigned int pos) {
  if (pos + 1 >= size)
    return seqs[pos];

  return seqs[pos] + 1 / fscf(seqs, size, pos + 1);
}

int main() {
  unsigned int size;
  int seqs[500];

  std::cin >> size;

  for (unsigned int i{0}; i < size; ++i) {
    std::cin >> seqs[i];
    std::cout << std::setprecision(10) << fscf(seqs, i + 1, 0) << std::endl;
  }
}
