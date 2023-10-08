#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  int val = 101;
  switch (val) {
    case 10:
      std::cout << val;
      break;
    case 100:
    case 200:
      std::cout << val;
      break;
    default:
      std::cout << "invalid!";
  }
  return EXIT_SUCCESS;
}
