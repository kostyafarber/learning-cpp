#include <vector>
template <typename T> class UniquePointer {
  T *ptr;

public:
  // explicit keyword
  explicit UniquePointer(T *p = nullptr) : ptr(p) {};
  ~UniquePointer() { delete ptr; }

  // TODO: You'll implement:
  // 1. Move operations (building on today's learning)
  // a move constructor for p2 UniquePointer(move(p1))
  UniquePointer(UniquePointer &&other) : ptr(other.ptr) { other.ptr = nullptr; }

  // 2. Some basic operators (-> and *)
  // these need to be const member functions
  T *operator->() const { return ptr; }
  T &operator*() const { return *ptr; }

  // move assignment allows: p2 = move(p1)
  // why do we need && in move syntax
  T operator=(UniquePointer &&other) {
    ptr = other.ptr;
    other.ptr = nullptr;
  }

  // 3. Release() method
  T *release() {
    T *tmp = ptr;
    ptr = nullptr;
    return tmp;
  }

  // copy is constructor
  UniquePointer(const UniquePointer &) = delete;

  // assignment is an operator overload
  UniquePointer &operator=(const UniquePointer &) = delete;
};

int main() {
  UniquePointer<std::vector<int>> p(new std::vector<int>{1, 2, 3, 4, 5});

  p->push_back(6);
  (*p).push_back(7);

  auto raw = p.release();
  raw->push_back(8);

  delete raw;
}