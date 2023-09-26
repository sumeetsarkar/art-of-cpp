#include <cstdlib>
#include <functional>
#include <iostream>

int main(int argc, char **argv) {
  std::function<int(void)> demo = []() { return 10; };
  std::cout << demo() << std::endl;

  int32_t value = 10;
  std::function<int(void)> demo2 = [=]() { return value; };
  std::cout << demo2() << std::endl;
  std::cout << "value: " << value << std::endl;

  int32_t initial = 100;
  std::function<int32_t(void)> increment = [&]() {
    initial += 10;
    return initial;
  };
  std::cout << increment() << std::endl;
  std::cout << increment() << std::endl;
  std::cout << increment() << std::endl;
  std::cout << "initial: " << initial << std::endl;
  return EXIT_SUCCESS;
}
