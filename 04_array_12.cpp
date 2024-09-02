#include <cassert>
#include <cstddef>
#include <cstring>
#include <iostream>

// Very simple hash map, no linked list implemented, just an array of string.
// throw error if hash value is duplicated.
class SimpleHashMap {
public:
  SimpleHashMap(size_t max_size) : m_max_size{max_size} {
    initial_reserve(m_max_size);
  }
  ~SimpleHashMap() { delete[] m_data; }

  void insert(const std::string &key, std::string &&value) {
    assert(m_data[std::hash<std::string>{}(key) % m_max_size] == "");
    m_data[std::hash<std::string>{}(key) % m_max_size] = std::move(value);
  }

  std::string look_up(const std::string &key) {
    return m_data[std::hash<std::string>{}(key) % m_max_size];
  }

  bool contain(const std::string &key) {
    return m_data[std::hash<std::string>{}(key) % m_max_size] != "";
  }

private:
  size_t m_max_size;
  std::string *m_data;

  void initial_reserve(size_t max_size) {
    m_data = new std::string[max_size];
    for (size_t i{0}; i < max_size; ++i)
      m_data[i] = "";
  }
};

int main() {
  SimpleHashMap shm(150); // don't change this magic number, if changed must be
                          // greater than 150
  shm.insert("Robert", "Dick");
  shm.insert("Dick", "Robert");
  shm.insert("William", "Bill");
  shm.insert("Bill", "William");
  shm.insert("James", "Jim");
  shm.insert("Jim", "James");
  shm.insert("John", "Jack");
  shm.insert("Jack", "John");
  shm.insert("Margaret", "Peggy");
  shm.insert("Peggy", "Margaret");
  shm.insert("Edward", "Ed");
  shm.insert("Ed", "Edward");
  shm.insert("Sarah", "Sally");
  shm.insert("Sally", "Sarah");
  shm.insert("Andrew", "Andy");
  shm.insert("Andy", "Andrew");
  shm.insert("Anthony", "Tony");
  shm.insert("Tony", "Anthony");
  shm.insert("Deborah", "Debbie");
  shm.insert("Debbie", "Deborah");

  unsigned int q;
  std::string name;

  std::cin >> q;

  while (q--) {
    std::cin >> name;
    if (!shm.contain(name))
      std::cout << "Not found" << std::endl;
    else
      std::cout << shm.look_up(name) << std::endl;
  }
}
