#include <cstddef>
#include <memory>

class FileBuffer {
private:
  std::unique_ptr<char[]> data;
  size_t size;

public:
  FileBuffer(size_t s) : size(s) { data = std::make_unique<char[]>(s); }

  // move constructor (buffer should only ever have one owner?)
  FileBuffer(FileBuffer &&other) {
    data = std::move(other.data);
    size = other.size;
  }

  // a move should return a reference to the object itself to allow for chained
  // assignment a = b = c;
  FileBuffer &operator=(FileBuffer &&other) noexcept {
    data = std::move(other.data);
    size = other.size;
    return *this;
  }

  FileBuffer(const FileBuffer &other) = delete;

  // should be const and return references
  FileBuffer &operator=(const FileBuffer &other) = delete;

  size_t get_size() const { return this->size; }

  /*
    so you can have a const and non const function that will enforce compile
    time checks
    */
  char *get_data() { return data.get(); }
  const char *get_data() const { return data.get(); }
};

int main() {
  FileBuffer b(2);

  b.get_data()[1] = 'C';
}
