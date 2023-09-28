#include <cstdlib>
#include <iostream>

void hello() {
  int val = 40;
  std::cout << val << ", \n";
}

namespace inner {
int val = 30;
int size = 100;
}  // namespace inner

int main(int argc, char **argv) {
  int val = 10;
  std::cout << val << ", \n";

  {
    int val = 20;
    std::cout << val << ", \n";
  }

  std::cout << inner::val << ", \n";
  std::cout << val << ", \n";

  // std::cout << size << ", \n"; // compilation error
  using namespace inner;
  std::cout << val << ", \n";  // still the current scope has val
  std::cout << size << ", \n";

  hello();
  return EXIT_SUCCESS;
}
