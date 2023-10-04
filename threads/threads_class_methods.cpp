#include <cstdlib>
#include <iostream>
#include <thread>

class Task {
 public:
  void run(int limit) {
    for (int i = 0; i < limit; i++) std::cout << i << "-";
  }

  static void s_run() { std::cout << "\nstatic run started!\n"; }
};

void foo() { std::cout << "\nfoo started!\n"; }

int main(int argc, char **argv) {
  Task task;
  std::thread t(&Task::run, &task, 10000);
  std::thread t_static(&Task::s_run);
  std::thread t_foo(foo);

  t_foo.join();
  t_static.join();

  std::cout << "\njust before the detach call\n";
  t.detach();
  return EXIT_SUCCESS;
}
