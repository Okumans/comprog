#include <cmath>
#include <iostream>
#include <queue>
#include <string>

struct Queue {
  int queue_name;
  int start_time;
};

class WaitTime {
public:
  void add_wait_time(int wait_time) {
    ++m_numbers;
    m_total_time_wasted += wait_time;
  }

  double get_average() const {
    return m_total_time_wasted / static_cast<double>(m_numbers);
  }

  double get_total_time() const { return m_total_time_wasted; }

private:
  int m_numbers{0};
  int m_total_time_wasted{0};
};

void reset(int &current_queue) {
  int new_queue;
  std::cin >> new_queue;
  current_queue = new_queue;
}

void new_queue(int &current_queue, std::queue<Queue> &queues) {
  int current_time;
  std::cin >> current_time;

  std::cout << ">> ticket " << current_queue << "\n";
  queues.push({current_queue++, current_time});
}

void next_queue(std::queue<Queue> &queues) {
  queues.pop();
  std::cout << ">> call " << queues.front().queue_name << "\n";
}

void order(std::queue<Queue> &queues, WaitTime &wait_times) {
  int current_time;
  std::cin >> current_time;

  Queue &front{queues.front()};

  std::cout << ">> qtime " << front.queue_name << " "
            << current_time - front.start_time << "\n";

  wait_times.add_wait_time(current_time - front.start_time);
}

void average_queue_time(WaitTime &wait_times) {
  std::cout << ">> avg_qtime "
            << std::round(wait_times.get_average() * 100) / 100.0 << "\n";
}

int main() {
  std::string command;
  std::queue<Queue> queues;
  WaitTime wait_times;

  int current_queue, n;
  queues.push(Queue());

  std::cin >> n;
  for (int i{0}; i < n; ++i) {
    std::cin >> command;

    if (command == "reset")
      reset(current_queue);

    else if (command == "new")
      new_queue(current_queue, queues);

    else if (command == "next")
      next_queue(queues);

    else if (command == "order")
      order(queues, wait_times);

    else if (command == "avg_qtime")
      average_queue_time(wait_times);
  }
}
