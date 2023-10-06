#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char **argv) {
  std::string sentance = "the quick brown fox jumps over the lazy dog";
  std::stringstream ss(sentance);
  std::string token;
  const char delim = ' ';
  while (std::getline(ss, token, delim)) {
    std::cout << token << "\n";
  }
  return EXIT_SUCCESS;
}
