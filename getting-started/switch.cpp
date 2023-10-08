#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  int val = 400;
  switch (val) {
    case 10:
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
