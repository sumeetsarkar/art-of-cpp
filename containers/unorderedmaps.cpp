#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>

struct data {
  int32_t id;
  std::string desc;
};

int main(int argc, char **argv) {
  std::unordered_map<std::string, data> umap;
  umap["ironman"] = data{1, "witty,supersmart"};
  umap["captainamerica"] = data{2, "leader,brave"};

  for (auto &[key, value] : umap) {
    auto &[id, desc] = value;
    std::cout << key << ":" << id << ", " << desc << std::endl;
  }
  return EXIT_SUCCESS;
}
