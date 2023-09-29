#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>

struct Superhero {
  std::string name;
  std::string desc;

  bool operator==(const Superhero &other) const {
    return this->name == other.name;
  }
};

namespace std {
template <>
struct std::hash<Superhero> {
  size_t operator()(const Superhero &s) const {
    return std::hash<std::string>()(s.name);
  }
};
}  // namespace std

int main(int argc, char **argv) {
  std::unordered_map<Superhero, int32_t> umap;
  umap[Superhero{"captainamerica", "leader, brave"}] = 1;
  umap[Superhero{"ironman", "witty, supersmart"}] = 2;

  for (auto &[key, rank] : umap) {
    auto &[name, desc] = key;
    std::cout << rank << ":" << name << ", " << desc << std::endl;
  }
  return EXIT_SUCCESS;
}
