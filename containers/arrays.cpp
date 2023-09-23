#include <array>
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  std::cout << "arrays" << std::endl;

  std::array<int32_t, 6> arr = {9, 10, 20, 30, 40, 50};
  for (int32_t i = 0; i < arr.size(); i++)
    std::cout << i << ": " << arr[i] << ", " << arr.at(i) << std::endl;

  std::cout << "maxsize: " << arr.max_size() << std::endl;
  std::cout << "empty: " << arr.empty() << std::endl;

  std::cout << "begin: " << arr.begin() << ", value: " << *arr.begin()
            << std::endl;
  std::cout << "end: " << arr.end() - 1 << ", value: " << *(arr.end() - 1)
            << std::endl;

  for (auto i = arr.begin(); i != arr.end(); i++)
    std::cout << i << ": " << *i << std::endl;

  arr.at(10); //  uncaught exception of type std::out_of_range: array::at

  return EXIT_SUCCESS;
}
