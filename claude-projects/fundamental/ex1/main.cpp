#include <format>
#include <iostream>

using namespace std;

// Starting template to work from:
class BufferWrapper {

public:
  int *data;
  size_t size;
  // Constructor already provided
  explicit BufferWrapper(size_t n) : size(n) {
    data = new int[n];
    std::cout << "Buffer created with size " << n << "\n";
  }

  // TODO: Implement these operations:
  // 1. Move constructor
  BufferWrapper(BufferWrapper &&other) : size(other.size), data(other.data) {
    cout << "move being called" << endl;

    delete[] other.data;
    other.data = nullptr;
    other.size = 0;
  }

  // 2. Destructor
  ~BufferWrapper() {
    cout << "destructor is being called" << endl;

    // just nulling it out doesn't delete it off the heap
    delete[] data;
    data = nullptr;
    size = 0;
  }

  // 3. Delete copy operations
  BufferWrapper(const BufferWrapper &) = delete;
  BufferWrapper &operator=(const BufferWrapper &) = delete;
};

int main() {

  BufferWrapper b1(5);
  cout << format("b1 creating with size: {}\n", b1.size);

  // b2 = b1 would cause a compile time error
}