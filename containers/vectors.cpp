#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  cout << "Vectors\n";
  vector<int32_t> vec;

  for (int32_t i = 0; i < 10; i++) {
    vec.push_back(i * 10);
    cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << endl;
  }

  for (int32_t i = 0; i < 10; i++) cout << vec[i] << ", ";

  cout << endl;
  cout << "size: " << vec.size() << endl;
  cout << "capacity: " << vec.capacity() << endl;
  cout << "maxsize: " << vec.max_size() << endl;

  cout << "front: " << vec.front() << endl;
  cout << "back: " << vec.back() << endl;

  cout << "begin: " << *vec.begin() << endl;
  cout << "end: " << *vec.end() << endl;

  vector<int>::iterator it = vec.begin();
  while (it != vec.end()) {
    cout << " " << *it << ", ";
    it++;
  }

  cout << endl;
  // or written as
  for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    cout << " " << *it << ", ";

  cout << endl;
  int32_t popped = vec.at(vec.size() - 1);
  vec.pop_back();
  cout << "Popped: " << popped << endl;

  for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    cout << " " << *it << ", ";

  cout << endl;
  cout << "size: " << vec.size() << endl;
  cout << "capacity: " << vec.capacity() << endl;
  cout << "shrink" << endl;

  vec.shrink_to_fit();
  cout << "size: " << vec.size() << endl;
  cout << "capacity: " << vec.capacity() << endl;

  cout << "[]: " << vec[4] << endl;
  cout << "at: " << vec.at(4) << endl;
  cout << "data: " << *(vec.data() + 4) << endl;

  cout << "reverse" << endl;
  reverse(vec.begin(), vec.end());
  for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    cout << " " << *it << ", ";

  cout << endl;
  cout << "reverse using reverse iterator" << endl;
  for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
    cout << " " << *it << ", ";

  vec.resize(20);
  cout << endl;
  cout << "size: " << vec.size() << endl;
  cout << "capacity: " << vec.capacity() << endl;

  for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    cout << " " << *it << ", ";

  // out of bounds access?
  cout << endl;
  cout << "at 21: "
       << vec.at(21);  // uncaught exception of type std::out_of_range: vector
  return EXIT_SUCCESS;
}
