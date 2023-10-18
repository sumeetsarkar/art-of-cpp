#include <algorithm>
#include <cstdlib>
#include <iostream>

class Solution {
 public:
  std::string sortString(std::string s) {
    std::string res = "";
    int counts[26] = {};
    for (int i = 0; i < 26; i++) counts[i] = 0;

    std::string unique_str = "";
    for (char c : s) {
      counts[c - 97] += 1;
      if (counts[c - 97] == 1) {
        unique_str += c;
      }
    }
    std::sort(unique_str.begin(), unique_str.end());
    std::string unique_str_r = unique_str;
    std::reverse(unique_str_r.begin(), unique_str_r.end());
    bool flip = false;

    while (true) {
      bool counts_zero = true;
      for (char c : flip ? unique_str_r : unique_str) {
        if (counts[c - 97]) {
          counts_zero = false;
          res += c;
          counts[c - 97] -= 1;
        }
      }
      flip = !flip;
      if (counts_zero) break;
    }
    return res;
  }
};

int main(int argc, char **argv) {
  Solution sol;
  std::cout << sol.sortString("aaaabbbbcccc") << "\n";
  std::cout << sol.sortString("abbbcc") << "\n";
  std::cout << sol.sortString("rat") << "\n";
  std::cout << sol.sortString("") << "\n";
  std::cout << sol.sortString("a") << "\n";
  std::cout << sol.sortString("ccba") << "\n";

  return EXIT_SUCCESS;
}
