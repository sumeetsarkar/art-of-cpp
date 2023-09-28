#include <cstdlib>
#include <iostream>

int size = 100;

void greet() { std::cout << "hello main\n"; }

// int value; // duplicate symbol [linker command failed]
extern int value;

int main(int argc, char **argv) {
  std::cout << size << std::endl;
  greet();
  std::cout << value << std::endl;
  return EXIT_SUCCESS;
}
