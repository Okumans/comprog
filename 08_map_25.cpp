#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int main() {
  int numbers;
  std::unordered_map<std::string, std::vector<std::string>> map_id2class;
  std::unordered_map<std::string, std::vector<std::string>> map_class2id;
  std::unordered_map<std::string, int> map_id2order;
  std::string id_buffer, class_buffer;

  std::cin >> numbers;
  for (int i{0}; i < numbers; ++i) {
    std::cin >> id_buffer;

    while (std::cin >> class_buffer && class_buffer != "*") {
      map_id2order[id_buffer] = i;
      map_id2class[id_buffer].push_back(class_buffer);
      map_class2id[class_buffer].push_back(id_buffer);
    }
  }

  std::cin >> id_buffer;

  std::unordered_set<std::string> printed;
  printed.insert(id_buffer);

  std::vector<std::pair<int, std::string>> result_student_id_by_order;

  for (const std::string &class_id : map_id2class[id_buffer]) {
    for (const std::string &student_id : map_class2id[class_id]) {
      if (printed.find(student_id) != printed.end())
        continue;

      result_student_id_by_order.emplace_back(map_id2order[student_id],
                                              student_id);
      printed.insert(student_id);
    }
  }

  printed.erase(id_buffer);
  if (printed.empty())
    std::cout << ">> Not Found\n";

  std::sort(result_student_id_by_order.begin(),
            result_student_id_by_order.end());
  for (const auto &pairr : result_student_id_by_order) {
    std::cout << ">> " << pairr.second << "\n";
  }
}
