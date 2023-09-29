#include <cstdlib>
#include <string>
#include <iostream>

class String {
  char *buffer;
  size_t size;

 public:
  String() = default;

  String(const char *s) {
    size = strlen(s) + 1;
    buffer = new char[size];
    std::memcpy(buffer, s, size - 1);
    buffer[size] = 0x00;
    printf("string created: %s\n", buffer);
  }

  String(const String &other) {
    size = other.size;
    buffer = new char[size];
    std::memcpy(buffer, other.buffer, size - 1);
    buffer[size] = 0x00;
    printf("string copied: %s\n", buffer);
  }

  String (String &&other) noexcept {
    size = other.size;
    buffer = other.buffer;
    other.size = 0;
    other.buffer = nullptr;
    printf("string moved: %s\n", buffer);
  }

  String &operator=(String &&other) noexcept {
    if (this != &other) {
      size = other.size;
      delete[] buffer;
      buffer = other.buffer;
      other.size = 0;
      other.buffer = nullptr;
    }
    printf("string moved by assignment operator: %s\n", buffer);
    return *this;
  }

  ~String() {
    printf("string destroyed: %s\n", buffer);
    if (buffer)
      delete[] buffer;
    size = 0;
  }

  friend std::ostream &operator<<(std::ostream &stream, const String &s) {
    if (s.buffer)
      stream << s.buffer;
    return stream;
  }
};

int main(int argc, char **argv) {
  {
    // Move
    std::cout << "------------\n";
    String src = "bob";
    String dest = std::move(src); // Equivalent to
                                  // String dest = ((String &&)src);
                                  // i.e., convert the src to rvalue
    std::cout << "src:" << src << "\n";
    std::cout << "dest:" << dest << "\n";
  }

  {
    // Move by assignment operator
    std::cout << "------------\n";
    String src = "alice";
    String dest;
    std::cout << "src:" << src << "\n";
    std::cout << "dest:" << dest << "\n";

    dest = std::move(src);
    std::cout << "src:" << src << "\n";
    std::cout << "dest:" << dest << "\n";
  }

  {
    // Copy
    std::cout << "------------\n";
    String src = "Pete";
    String dest = src;
    std::cout << "src:" << src << "\n";
    std::cout << "dest:" << dest << "\n";
  }

  {
    // Reference
    std::cout << "------------\n";
    String src = "Pete";
    String &dest = src;
    std::cout << "src:" << src << "\n";
    std::cout << "dest:" << dest << "\n";
  }
  return EXIT_SUCCESS;
}