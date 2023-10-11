#include <array>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  cout << "arrays" << endl;

  array<int32_t, 6> arr = {9, 10, 20, 30, 40, 50};
  for (int32_t i = 0; i < arr.size(); i++)
    cout << i << ": " << arr[i] << ", " << arr.at(i) << endl;

  cout << "maxsize: " << arr.max_size() << endl;
  cout << "empty: " << arr.empty() << endl;

  cout << "front: " << arr.front() << endl;
  cout << "back: " << arr.back() << endl;

  cout << "begin: " << arr.begin() << ", value: " << *arr.begin() << endl;
  cout << "end: " << arr.end() - 1 << ", value: " << *(arr.end() - 1) << endl;

  for (auto i = arr.begin(); i != arr.end(); i++)
    cout << i << ": " << *i << endl;

  cout << "fill array\n";
  arr.fill(0);

  for (auto i = arr.begin(); i != arr.end(); i++)
    cout << i << ": " << *i << endl;

  array<int32_t, 6> arr2 = {9, 10, 20, 30, 40, 50};
  arr2.swap(arr);

  for (auto i = arr.begin(); i != arr.end(); i++)
    cout << i << ": " << *i << endl;

  cout << "arr2\n";
  for (auto i = arr2.begin(); i != arr2.end(); i++)
    cout << i << ": " << *i << endl;

  array<int32_t, 10> arr3;
  arr3[0] = 1;
  arr3[1] = 2;
  cout << "arr3 size: " << arr3.size() << endl;
  cout << "arr3 maxsize: " << arr3.max_size() << endl;
  cout << "arr3: " << arr3[0] << ", " << arr3[1] << endl;
  cout << "arr3: " << arr3[9] << endl;

  // arr3.at(10);  //  uncaught exception of type out_of_range: array::at

  array<int32_t, 6> arr4 = {9, 10, 20, 30, 40, 50};
  // auto sort_asc = [](int a, int b) -> bool { return a < b; };
  // sort(arr4.begin(), arr4.end(), sort_asc);
  sort(arr4.begin(), arr4.end(), [](int a, int b) { return a < b; });
  for (auto num : arr4) std::cout << num << ",";
  std::cout << "\n";

  return EXIT_SUCCESS;
}
