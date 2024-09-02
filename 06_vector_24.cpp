
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <vector>

template <typename K, typename V, size_t base_capacity = 100> class Hashmap {
private:
  struct Node {
    K key;
    V value;
    Node *next;
  };

  std::vector<Node *> m_table;
  size_t m_size{0};

private:
  template <typename T> size_t generate_hash(T value, size_t capacity) const {
    return static_cast<size_t>(std::hash<T>{}(value)*M_PI * 1414129) % capacity;
  }

  void resize_hashmap() {
    size_t new_capacity = m_table.size() * 2;
    std::vector<Node *> temp(new_capacity, nullptr);

    for (Node *entry : m_table) {
      Node *node_ptr = entry;
      while (node_ptr != nullptr) {
        size_t hashed{generate_hash<K>(node_ptr->key, new_capacity)};
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

  bool empty() const { return m_size == 0; }

  size_t size() const { return m_size; }

  bool contain(const K &key) const {
    size_t hashed = generate_hash<K>(key, m_table.size());

    Node *node_ptr = m_table[hashed];
    while (node_ptr != nullptr) {
      if (key == node_ptr->key)
        return true;
      node_ptr = node_ptr->next;
    }

    return false;
  }

  void insert(const K &key, const V &value) {
    if (m_size >= m_table.size()) {
      resize_hashmap();
    }
    size_t hashed{generate_hash<K>(key, m_table.size())};

    Node *node_ptr{m_table[hashed]};
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

  void insert(const K &key, V &&value) {
    if (m_size >= m_table.size()) {
      resize_hashmap();
    }
    size_t hashed{generate_hash<K>(key, m_table.size())};

    Node *node_ptr{m_table[hashed]};
    while (node_ptr != nullptr) {
      if (key == node_ptr->key) {
        node_ptr->value = std::move(value);
        return;
      }

      node_ptr = node_ptr->next;
    }

    Node *new_node = new Node{key, value, m_table[hashed]};
    m_table[hashed] = new_node;
    ++m_size;
  }

  V get(const K &key) const {
    size_t hashed{generate_hash<K>(key, m_table.size())};

    Node *node_ptr{m_table[hashed]};
    while (node_ptr != nullptr) {
      if (key == node_ptr->key)
        return node_ptr->value;
      node_ptr = node_ptr->next;
    }

    throw std::range_error("Key not found.");
  }

  V &access(const K &key) {
    size_t hashed{generate_hash<K>(key, m_table.size())};

    Node *node_ptr{m_table[hashed]};
    while (node_ptr != nullptr) {
      if (key == node_ptr->key)
        return node_ptr->value;
      node_ptr = node_ptr->next;
    }

    throw std::range_error("Key not found.");
  }

  V pop(const K &key) {
    size_t hashed{generate_hash<K>(key, m_table.size())};

    Node *node_ptr{m_table[hashed]};
    Node *prev_ptr{nullptr};

    while (node_ptr != nullptr) {
      if (key == node_ptr->key) {
        if (prev_ptr == nullptr) {
          m_table[hashed] = node_ptr->next; // Remove the head node
        } else {
          prev_ptr->next = node_ptr->next; // Remove a non-head node
        }
        V result{node_ptr->value};
        delete node_ptr;
        --m_size;
        return result;
      }

      prev_ptr = node_ptr;
      node_ptr = node_ptr->next;
    }

    throw std::range_error("Key not found.");
  }

  std::vector<K> keys() const {
    std::vector<K> keys;

    for (Node *entry : m_table) {
      while (entry != nullptr) {
        keys.push_back(entry->key);
        entry = entry->next;
      }
    }

    return keys;
  }

  std::vector<V> values() const {
    std::vector<V> values;

    for (Node *entry : m_table) {
      while (entry != nullptr) {
        values.push_back(entry->value);
        entry = entry->next;
      }
    }

    return values;
  }

  std::vector<std::pair<K, V>> to_pairs() const {
    std::vector<std::pair<K, V>> values;

    for (Node *entry : m_table) {
      while (entry != nullptr) {
        values.emplace_back(entry->key, entry->value);
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
  Hashmap<std::string, std::pair<double, int>> map;

  std::string goods_id;
  double cost;

  while (std::cin >> goods_id && goods_id != "END" && std::cin >> cost) {
    map.insert(goods_id, {cost, 0});
  }

  while (std::cin >> goods_id) {
    if (map.contain(goods_id))
      map.access(goods_id).second++;
  }

  auto pairs{map.to_pairs()};
  std::sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b) {
    return a.second.first * a.second.second == b.second.first * b.second.second
               ? a.first < b.first
               : a.second.first * a.second.second >
                     b.second.first * b.second.second;
  });

  if (!pairs[0].second.second) {
    std::cout << "No Sales";
    return 0;
  }

  for (int i{0}; i < std::min(static_cast<size_t>(3), pairs.size()); ++i) {
    if (!pairs[i].second.second)
      break;

    std::cout << pairs[i].first << " "
              << pairs[i].second.first * pairs[i].second.second << '\n';
  }
}
