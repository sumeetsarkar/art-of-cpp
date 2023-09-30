#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

class FileReadHandler {
  std::ifstream fin;

 public:
  explicit FileReadHandler(std::string path) {
    fin.open(path, std::ios_base::in);
    std::cout << "fin opened: " << path << std::endl;
  }
  ~FileReadHandler() {
    fin.close();
    std::cout << "fin closed\n";
  }

  bool has_more_to_read() { return fin && fin.peek(); }

  std::string read() {
    std::string line;
    std::getline(fin, line);
    return line;
  }
};

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Usage <prog> <file_path>\n";
    return EXIT_FAILURE;
  }
  {
    FileReadHandler fh(argv[1]);
    while (fh.has_more_to_read()) {
      std::cout << fh.read() << std::endl;
    }
  }
  return EXIT_SUCCESS;
}
