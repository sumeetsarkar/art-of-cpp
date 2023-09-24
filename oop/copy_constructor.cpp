#include <string.h>

#include <cstdlib>
#include <cstring>
#include <iostream>

class String {
  char *buffer;
  int size;

 public:
  String(const char *str) {
    this->size = strlen(str);
    this->buffer = new char[this->size + 1];
    this->buffer[this->size] = 0x00;
    std::memcpy(this->buffer, str, this->size);
  }

  String(const String &other) {
    std::cout << ">> copy constructor\n";
    this->size = other.size;
    this->buffer = new char[this->size + 1];
    std::memcpy(this->buffer, other.buffer, this->size);
    this->buffer[this->size] = 0x00;
  }

  ~String() {
    this->size = 0;
    delete[] this->buffer;
  }

  char &operator[](int index);
  friend std::ostream &operator<<(std::ostream &stream, const String &string);
};

char &String::operator[](int index) { return this->buffer[index]; }

std::ostream &operator<<(std::ostream &stream, const String &string) {
  stream << string.buffer;
  return stream;
}

void print_copy_values(String str) { std::cout << str << std::endl; }

void print_copy_reference(const String &str) { std::cout << str << std::endl; }

int main(int argc, char **argv) {
  String str1 = "test string";
  String str2 = str1;

  std::cout << str1 << std::endl;
  std::cout << str2 << std::endl;

  str2[0] = 'b';
  std::cout << str1 << std::endl;
  std::cout << str2 << std::endl;

  print_copy_values(str2);
  print_copy_reference(str2);
  return EXIT_SUCCESS;
}
