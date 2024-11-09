/*
Exercise: Memory-Mapped File Reader

Create a class that:
1. Opens a file using low-level system calls
2. Maps it into memory using mmap (Unix) or MapViewOfFile (Windows)
3. Provides safe access to the mapped region
4. Properly cleans up resources

Requirements:
1. Use RAII for resource management
2. Handle system call errors appropriately
3. Provide a view into the mapped memory
4. Clean up properly even if errors occur

Start with this skeleton:
*/

#include <cstddef>
#include <exception>
#include <fcntl.h> // for open
#include <format>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sys/fcntl.h>
#include <sys/mman.h> // for mmap
#include <sys/stat.h> // for fstat
#include <unistd.h>   // for close

class MemoryMappedFile {
  // TODO: Add member variables for:
  // - File descriptor
  int fd;

  // - Mapped memory pointer (what type)
  void *ptr;

  // - Size of mapped region
  size_t mapped_size;

public:
  // TODO: Implement constructor that takes a filename
  explicit MemoryMappedFile(const std::string &filename) {
    auto fd = open(filename.c_str(), O_RDONLY);
    if (fd == -1) {
      close(fd);
      throw std::runtime_error(std::format("error opening file: {}", fd));
    }

    struct stat s;
    auto err = fstat(fd, &s);
    if (err == -1) {
      close(fd);
      std::runtime_error("failed to get stats for file");
    }

    mapped_size = s.st_size;

    void *addr = mmap(nullptr, mapped_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
      close(fd);
      throw std::runtime_error("mmap failed");
    }

    ptr = addr;
  }

  // TODO: Implement destructor to clean up resources
  ~MemoryMappedFile() {}

  // TODO: Delete copy operations (why?)
  MemoryMappedFile(const MemoryMappedFile &) = delete;
  MemoryMappedFile &operator=(const MemoryMappedFile &) = delete;

  // TODO: Implement methods to:
  // - Get pointer to mapped memory
  const char *data() const { return static_cast<const char *>(ptr); }

  // - Get size of mapped region
  size_t size() const { return mapped_size; }

  // - Check if mapping is valid
};

// Example usage:
int main() {
  try {
    MemoryMappedFile file("test.txt");

    // Should print contents and size
    std::cout << "File size: " << file.size() << " bytes\n";
    std::cout << "Contents: " << std::string(file.data(), file.size()) << "\n";

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  return 0;
}