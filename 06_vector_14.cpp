#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

template <size_t base_capacity = 100> class Hashmap {
private:
  struct Node {
    int key;
    int value;
    Node *next;
  };

  std::vector<Node *> m_table;
  size_t m_size{0};

private:
  size_t generate_hash(int value) const {
    return static_cast<size_t>(value * M_PI * 1414129) % m_table.size();
  }

  void resize_hashmap() {
    size_t new_capacity = m_table.size() * 2;
    std::vector<Node *> temp(new_capacity, nullptr);

    for (Node *entry : m_table) {
      Node *node_ptr = entry;
      while (node_ptr != nullptr) {
        size_t hashed =
            static_cast<size_t>(node_ptr->key * M_PI * 1414129) % new_capacity;
        Node *next_node = node_ptr->next;

        node_ptr->next = temp[hashed];
        temp[hashed] = node_ptr;

        node_ptr = next_node;
      }
    }

    m_table = std::move(temp);
  }

public:
  Hashmap() : m_table(base_capacity, nullptr) {}

  bool empty() { return m_size == 0; }

  bool size() { return m_size; }

  bool contain(int key) {
    size_t hashed = generate_hash(key);

    Node *node_ptr = m_table[hashed];
    while (node_ptr != nullptr) {
      if (key == node_ptr->key)
        return true;
      node_ptr = node_ptr->next;
    }

    return false;
  }

  void insert(int key, int value) {
    if (m_size >= m_table.size()) {
      resize_hashmap();
    }
    size_t hashed = generate_hash(key);

    Node *node_ptr = m_table[hashed];
    while (node_ptr != nullptr) {
      if (key == node_ptr->key) {
        node_ptr->value = value;
        return;
      }

      node_ptr = node_ptr->next;
    }

    Node *new_node = new Node{key, value, m_table[hashed]};
    m_table[hashed] = new_node;
    ++m_size;
  }

  int get(int key) const {
    size_t hashed = generate_hash(key);

    Node *node_ptr = m_table[hashed];
    while (node_ptr != nullptr) {
      if (key == node_ptr->key)
        return node_ptr->value;
      node_ptr = node_ptr->next;
    }

    throw std::range_error("Key not found.");
  }

  int pop(int key) {
    size_t hashed = generate_hash(key);

    Node *node_ptr = m_table[hashed];
    Node *prev_ptr = nullptr;

    while (node_ptr != nullptr) {
      if (key == node_ptr->key) {
        if (prev_ptr == nullptr) {
          m_table[hashed] = node_ptr->next; // Remove the head node
        } else {
          prev_ptr->next = node_ptr->next; // Remove a non-head node
        }
        int result = node_ptr->value;
        delete node_ptr;
        --m_size;
        return result;
      }

      prev_ptr = node_ptr;
      node_ptr = node_ptr->next;
    }

    throw std::range_error("Key not found.");
  }

  std::vector<int> keys() const {
    std::vector<int> keys;

    for (Node *entry : m_table) {
      while (entry != nullptr) {
        keys.push_back(entry->key);
        entry = entry->next;
      }
    }

    return keys;
  }

  std::vector<int> values() const {
    std::vector<int> values;

    for (Node *entry : m_table) {
      while (entry != nullptr) {
        values.push_back(entry->value);
        entry = entry->next;
      }
    }

    return values;
  }

  ~Hashmap() {
    for (Node *entry : m_table) {
      while (entry != nullptr) {
        Node *next = entry->next;
        delete entry;
        entry = next;
      }
    }
  }
};

int main() {
  Hashmap<120> map;
  int buffer;

  while (std::cin >> buffer) {
    map.insert(buffer, 0);
  }

  std::vector<int> keys{map.keys()};
  std::sort(keys.begin(), keys.end());
  std::cout << keys.size() << "\n";

  bool printed{false};
  for (int ind{0}; ind < std::min(static_cast<size_t>(10), keys.size());
       ++ind) {
    if (!printed)
      printed = true;
    else
      std::cout << " ";

    std::cout << keys[ind];
  }

  std::cout << std::endl;
}
