#include <cstdlib>
#include <iostream>
#include <queue>

int main(int argc, char **argv) {
  std::priority_queue<int> pq;
  pq.push(12);
  pq.push(98);
  pq.push(8);
  pq.push(23);
  pq.push(5);
  pq.push(2);
  pq.push(65);
  pq.push(33);
  pq.push(78);

  while (pq.size()) {
    std::cout << pq.top() << ", ";
    pq.pop();
  }
  std::cout << std::endl;

  class Comparator {
   public:
    bool operator()(int a, int b) { return a > b; }
  };
  std::priority_queue<int, std::vector<int>, Comparator> min_heap;
  min_heap.push(12);
  min_heap.push(98);
  min_heap.push(8);
  min_heap.push(23);
  min_heap.push(5);
  min_heap.push(2);
  min_heap.push(65);
  min_heap.push(33);
  min_heap.push(78);

  while (min_heap.size()) {
    std::cout << min_heap.top() << ", ";
    min_heap.pop();
  }
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
