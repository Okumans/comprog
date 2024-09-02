#include <algorithm>
#include <cstdlib>
#include <iostream>

struct Point {
  int x, y;
};

class Rectangle {
  Point left;
  Point right;

public:
  Rectangle(Point left, Point right) : left{left}, right{right} {}
  Rectangle() : left{0, 0}, right{0, 0} {}

  bool is_point_in(Point point) const {
    return point.x > left.x && point.x < right.x && point.y > left.y &&
           point.y < right.y;
  }

  bool is_overlap(const Rectangle &other) const {
    return !(left.x >= other.right.x || right.x <= other.left.x ||
             left.y >= other.right.y || right.y <= other.left.y);
  }

  double overlap_area(const Rectangle &other) const {
    int overlap_left_x = std::max(left.x, other.left.x);
    int overlap_right_x = std::min(right.x, other.right.x);
    int overlap_bottom_y = std::max(left.y, other.left.y);
    int overlap_top_y = std::min(right.y, other.right.y);

    if (overlap_left_x < overlap_right_x && overlap_bottom_y < overlap_top_y) {
      int width = overlap_right_x - overlap_left_x;
      int height = overlap_top_y - overlap_bottom_y;
      return width * height;
    }

    return 0.0; // No overlap
  }
};

int main() {
  Point temp_a, temp_b;
  int numbers;

  std::cin >> numbers;
  Rectangle *rectangles{new Rectangle[numbers]};
  std::pair<int, int> *overlap_rectangles{
      new std::pair<int, int>[((numbers - 1) * numbers) / 2]};
  int max_overlap_area{static_cast<int>(-1e9)};
  int overlap_count{0};

  for (int i{0}; i < numbers; ++i) {
    std::cin >> temp_a.x >> temp_a.y >> temp_b.x >> temp_b.y;
    rectangles[i] = Rectangle(temp_a, temp_b);

    for (int j{0}; j < i; ++j) {
      if (rectangles[i].is_overlap(rectangles[j]) &&
          rectangles[j].is_overlap(rectangles[i])) {
        overlap_rectangles[overlap_count++] = {j, i};
        max_overlap_area = std::max(
            max_overlap_area,
            static_cast<int>(rectangles[i].overlap_area(rectangles[j])));

        std::cout << "(" << i << "," << j << "): "
                  << static_cast<int>(rectangles[i].overlap_area(rectangles[j]))
                  << "\n";
      }
    }
  }

  std::sort(overlap_rectangles, overlap_rectangles + overlap_count);

  if (max_overlap_area == static_cast<int>(-1e9))
    std::cout << "No overlaps\n";
  std::cout << "Max overlapping area = " << max_overlap_area << "\n";

  for (int i{0}; i < overlap_count; ++i) {
    std::cout << "rectangles " << overlap_rectangles[i].first << " and "
              << overlap_rectangles[i].second << "\n";
  }
}
// s dsfsad
