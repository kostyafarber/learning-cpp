#include <iostream>

typedef void (*TaskFunction)();

/*
TODO: Make an example diagram in mono draw

TODO: Implement a simple thread pool
Steps:
1. Set up the basic ThreadPool class structure
2. Implement the constructor to initialize worker threads
3. Create a task queue to store pending tasks
4. Implement the add_task method to enqueue new tasks
5. Develop the worker function for threads to execute tasks
6. Implement proper synchronization for the task queue
7. Create a shutdown method to stop all threads safely
8. Handle potential exceptions in task execution
9. Test the thread pool with various tasks
10. (Optional) Implement a method to get the number of pending tasks
*/
class ThreadPool {
public:
  int num_threads;
  std::vector<TaskFunction> tasks;

  ThreadPool(int n) { num_threads = n; }

  void add_task(TaskFunction t) { tasks.push_back(t); };
  void worker_function() {};
  void remove_task();
  void shutdown();
};

using namespace std;

int main() {
  ThreadPool pool(4);

  auto t = []() { cout << "Hello, World!" << endl; };
  pool.add_task(t);

  pool.tasks[0]();
}
