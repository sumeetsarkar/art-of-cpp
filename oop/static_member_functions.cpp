#include <cstdlib>
#include <iostream>

class Foo {
  inline static int foo_value = 10;

 public:
  static void func() /*const*/ {  // static functions cannot have const
    std::cout << "static Foo function\n";
    std::cout << foo_value << std::endl;
  }
  void function_regular() const {
    std::cout << "regular Foo function\n";
    std::cout << foo_value << std::endl;
  }
};

int main(int argc, char **argv) {
  Foo::func();
  Foo f;
  f.function_regular();
  return EXIT_SUCCESS;
}
