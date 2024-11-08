#include <format>
#include <iostream>
#include <queue>
#include <string>
#include <utility>

/*
Exercise: Task Queue Manager

Create a TaskQueue class that manages a list of tasks, where each task has:
- A name
- A priority level
- Some data to process (string)

Requirements:
1. TaskQueue should take ownership of tasks when they're added
2. When executing a task, it should print the task info and remove it from the
queue
3. Tasks should be executed in order of priority (highest first)

Start with this skeleton:
*/

using namespace std;

class Task {
  string name_;
  int priority_;
  string data_;

public:
  // TODO: Implement constructor(s)
  Task(string name, int priority, string data)
      : name_(name), priority_(priority), data_(data) {};

  // I need to actually move the items from other
  Task(const Task &other) noexcept
      : name_(move(other.name_)), priority_(other.priority_),
        data_(move(other.data_)) {};

  // I need to actually move the items from other
  Task(Task &&other) noexcept
      : name_(move(other.name_)), priority_(other.priority_),
        data_(move(other.data_)) {};

  Task &operator=(Task &&other) noexcept {
    data_ = other.data_;
    priority_ = other.priority_;
    name_ = other.name_;
    return *this;
  }

  // TODO: Add necessary getters
  string get_name() const { return this->name_; }
  string get_data() const { return this->data_; }
  int priority() const { return this->priority_; }
};

class TaskQueue {
  // TODO: Choose appropriate container for storing tasks

  class Compare {

    // needed to switch them why?
    bool operator()(Task a, Task b) { return (a.priority() < b.priority()); }
  };

  priority_queue<Task, vector<Task>, Compare> queue;

public:
  // thought this move would handle when I pop?
  void add_to_queue(Task t) { queue.push(std::move(t)); }

  void execute() {
    if (queue.empty()) {
      std::cout << "No tasks to execute\n";
      return;
    }

    // this is because it returns a const reference and we can't move that
    Task task = queue.top();
    queue.pop();

    std::cout << std::format(
        "Executing task: '{}' (priority: {}) with data: {}\n", task.get_name(),
        task.priority(), task.get_data());
  }
};

int main() {}