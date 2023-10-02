#include <cstdlib>
#include <iostream>
#include <thread>

void foo(int seq) {
  // thread body
  std::cout << "foo seq: " << seq << "\n";
}

void bar() {
  std::cout << "bar!\n";
  for (;;)
    ;
}

int main(int argc, char **argv) {
  std::thread t1(foo, 1);
  std::thread t2(foo, 10);
  std::thread t3(bar);
  std::cout << "threads t1, t2 and t3 are now executing concurrently\n";

  t1.join();
  t2.join();
  std::cout << "threads t1 and t2 are now completed\n";

  t3.detach();
  std::cout << "threads t3 is detached\n";
  return EXIT_SUCCESS;
}
