#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  int val = 400;
  switch (val) {
    int x;
    int y;
    // int z = 10; // initialization not allowed
    case 10:
      y = 20;  // initialize in case block
      std::cout << val;
      break;
    case 100:
      [[fallthrough]];
    case 200:
      [[fallthrough]];
    case 300:
      [[fallthrough]];
    case 400:
      [[fallthrough]];
    case 500:
      std::cout << val;
      break;
    default:
      std::cout << "invalid!";
  }
  return EXIT_SUCCESS;
}
