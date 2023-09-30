#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  int age;
  char name[16];

  std::cout << "enter name: ";
  std::cin.getline(name, 16);

  // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "enter age: ";
  std::cin >> age;

  std::cout << name << ", " << age << std::endl;
  return EXIT_SUCCESS;
}
