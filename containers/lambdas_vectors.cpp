#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char **argv) {
  std::vector<int> v1 = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};

  auto even =
      std::count_if(v1.begin(), v1.end(), [](int a) { return a % 2 == 0; });

  std::cout << even << std::endl;

  auto first_even =
      std::find_if(v1.begin(), v1.end(), [](int a) { return a % 2 == 0; });
  std::cout << *first_even << std::endl;

  std::vector<int> even_nums;
  std::copy_if(v1.begin(), v1.end(), std::back_inserter(even_nums),
               [](int a) { return a % 2 == 0; });
  for (auto i = even_nums.begin(); i != even_nums.end(); i++) {
    std::cout << *i << ", ";
  }
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
