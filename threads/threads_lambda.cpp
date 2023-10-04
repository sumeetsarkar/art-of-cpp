#include <cstdlib>
#include <iostream>
#include <thread>

int main(int argc, char **argv) {
  auto task1 = []() { std::cout << "\ntask1 started\n"; };
  std::thread t1(task1);
  t1.join();

  int state = 0;
  auto task2 = [&state](int inc, int limit) {
    std::cout << "\ntask2 started " << inc << "," << limit << "\n";
    for (int i = 0; i < limit; i++) {
      state += inc;
      std::cout << state << "-";
    }
  };
  auto task3 = [&state](int inc, int limit) {
    std::cout << "\ntask3 started " << inc << "," << limit << "\n";
    for (int i = 0; i < limit; i++) {
      state += inc;
      std::cout << state << "-";
    }
  };

  std::thread t2(task2, 1, 100);
  std::thread t3(task3, 5, 100);
  t3.join();
  t2.join();
  std::cout << "\nFinal state:" << state;
  return EXIT_SUCCESS;
}
