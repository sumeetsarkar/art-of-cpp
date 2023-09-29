#include <cstdlib>
#include <iostream>

// basic pass by value
std::string get_path1(const std::string dir, const std::string filename) {
  return dir + filename;
}

// pass by reference
std::string get_path2(std::string &dir, std::string &filename) {
  return dir + filename;
}

// pass by const reference
std::string get_path3(const std::string &dir, const std::string &filename) {
  return dir + filename;
}

// pass rvalue
std::string get_path4(const std::string &&dir, const std::string &&filename) {
  return dir + filename;
}

int get_num1() {
  return 1000;
}

int &get_num2() {
  int a = 100;
  return a; // just for demo
}

int main(int argc, char **argv) {
  int a = 10;
  // lvalue => a
  // rvalue => 10

  // 10 = a; // expression is not assignable

  // int &b = 10; // non-const lvalue, cannot bind to temporary type
  const int &c = 10; // SPECIAL RULE, this works!
  std::cout<< c;
  // get_num1() = 10; // Not allowed, expression is not assignable
  get_num2() = 10; // allowed

  std::string dir = "./";
  std::string filename = "hello_world.cpp";

  // passing both lvalue and rvalue work (pass by value)
  get_path1(dir, filename);
  get_path1("../", "hello.cpp");

  // Only explicit lvalues can be passed (non-const reference args)
  get_path2(dir, filename);
  // get_path2("../", "hello.cpp"); // non-const lvalue, cannot bind to temporary type

  // passing both lvalue and rvalue work (const reference args)
  get_path3(dir, filename);
  get_path3("../", "hello.cpp");

  // Only explicit rvalues can be passed (const && reference args)
  // get_path4(dir, filename); // compilation error - expects EXPLICITLY rvalue
  get_path4("../", "hello.cpp");
  // why do we care for passing rvalue directly?
  // Check for move semantics
  return EXIT_SUCCESS;
}
