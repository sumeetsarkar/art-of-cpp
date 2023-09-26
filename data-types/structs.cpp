#include <cstdlib>
#include <iostream>

using namespace std;

struct Point {
  int32_t x;
  int32_t y;

  void add(int32_t x, int32_t y) {
    this->x += x;
    this->y += y;
  }

  void print() { cout << "[" << this->x << ", " << this->y << "]" << endl; }
};

int main(int argc, char **argv) {
  Point p = {.x = 0, .y = 1};
  p.add(1, 1);
  p.print();

  return EXIT_SUCCESS;
}
