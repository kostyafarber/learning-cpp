#include <iostream>

class Counter {
public:
  static int m_count;

  Counter() { m_count++; }

  int get_count() { return m_count; }
};

// need to learn more about this why it's necessary
int Counter::m_count = 0;

int main() {
  using namespace std;

  Counter c1;
  cout << c1.get_count() << endl;

  // counting from c1 again to show it's been incremented
  Counter c2;
  cout << c1.get_count() << endl;
}