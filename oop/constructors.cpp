#include <cstdlib>
#include <iostream>

class demo {
  int *arr;
  std::string name;

 public:
  demo(std::string name) {
    this->name = name;
    std::cout << "demo constructor: " << name << std::endl;
    this->arr = new int[1];
    arr[0] = 0b100;
  }

  demo(std::string name, int size) {
    this->name = name;
    std::cout << "demo constructor: " << name << std::endl;
    this->arr = new int[size];
    arr[0] = 0b111;
  }

  ~demo() {
    std::cout << "~demo deconstructor: " << this->name << std::endl;
    std::cout << this->arr[0] << std::endl;
    delete[] this->arr;
  }
};

int main(int argc, char **argv) {
  demo d1("1");
  demo d2("2");
  demo d3("3", 10);

  demo *d4 = new demo("4");
  delete d4;
  return EXIT_SUCCESS;
}
