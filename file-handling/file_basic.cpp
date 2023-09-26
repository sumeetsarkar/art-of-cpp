#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
  std::ofstream fout;
  fout.open("sample.txt", std::ios_base::trunc);

  std::string line;
  while (fout) {
    std::getline(std::cin, line);
    if (line == "-l")
      break;
    fout << line << std::endl;
  }
  fout.close();

  std::ifstream fin;
  fin.open("sample.txt", std::ios_base::in);
  while (getline(fin, line)) {
    std::cout << line << std::endl;
  }
  fin.close();
  return EXIT_SUCCESS;
}