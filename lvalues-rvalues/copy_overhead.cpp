#include <cstring>
#include <cstdlib>
#include <iostream>

class String {
 private:
  char *buffer;
  size_t size;

 public:
  String(const char *str) {
    size_t n = strlen(str);
    size = n + 1;
    buffer = new char[size];
    std::memcpy(buffer, str, size);
    buffer[size] = 0x00;
    printf("String created: %s\n", buffer);
  }

  String(const String &other) {
    size = other.size + 1;
    buffer = new char[size];
    std::memcpy(buffer, other.buffer, size);
    buffer[size] = 0x00;
    printf("String copied: %s\n", buffer);
  }

  String(String &&other) noexcept {
    size = other.size;
    buffer = other.buffer;
    other.size = 0;
    other.buffer = nullptr;
    printf("String moved: %s\n", buffer);
  }

  ~String() {
    printf("String destroyed: %s\n", buffer);
    size = 0;
    delete buffer;
  }

  friend std::ostream &operator<<(std::ostream &stream, const String &s);
};

std::ostream &operator<<(std::ostream &stream, const String &s) {
  stream << s.buffer;
  return stream;
}

class EntityCopy {
 private:
  String m_str;

 public:
  explicit EntityCopy(const String &str)
      : m_str(str) {
    std::cout << "entity lvalue constructor\n";
  }
  explicit EntityCopy(const String &&str)
      : m_str(str) {
    std::cout << "entity rvalue constructor\n";
  }
  ~EntityCopy() = default;
};

class Entity {
 private:
  String m_str;

 public:
  explicit Entity(const String &str)
      : m_str(str) {
    std::cout << "entity lvalue constructor\n";
  }
  Entity(const String &&str)
      : m_str((String &&)str) {
    std::cout << "entity rvalue constructor\n";
  }

  ~Entity() = default;
  String &get_str() { return m_str; }
};

int main(int argc, char **argv) {
  {
    std::cout << "--------------\n";
    EntityCopy ec1("string will be copied");
  }

  {
    // effectively string char buffer gets 'new'd once and deleted once
    // the moved prev string is dereference to nullptr and deletes null on destroy
    // which is a noop
    std::cout << "--------------\n";
    Entity e1("string will be moved");
  }

  std::cout << "--------------\n";
  {
    Entity e2("helloworld");
    e2.get_str();
  }

  std::cout << "--------------\n";
  {
    Entity e3("helloworld2");
    String copy = e3.get_str();
  }
  return EXIT_SUCCESS;
}