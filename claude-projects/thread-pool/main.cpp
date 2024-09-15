#include <functional>
#include <iostream>

typedef void (*TaskFunction)();

class ThreadPool {
public:
  int num_threads;
  std::vector<TaskFunction> tasks;

  ThreadPool(int n) { num_threads = n; }

  void add_task(TaskFunction t) { tasks.push_back(t) }
  void remove_task();
  void shutdown();
};

using namespace std;

int main() { cout << "whatup" << endl; }
