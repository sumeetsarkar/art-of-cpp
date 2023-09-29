#include <cstdlib>
#include <iostream>

class Place {
  std::string name;
  std::string desc;

 public:
  Place() = delete;
  explicit Place(std::string name, std::string desc)
      : name(std::move(name)), desc(std::move(desc)) {}
  ~Place() {}

  void print() const;
  std::string& get_name();
  std::string get_desc() const;
};

void Place::print() const { std::cout << name << ", " << desc << std::endl; }

std::string& Place::get_name() { return name; }
std::string Place::get_desc() const { return desc; }

int main(int argc, char** argv) {
  Place p("Aengaluru", "IT City");
  p.get_name()[0] = 'B';  // return by reference
  p.get_desc()[0] = 'A';  // return by value, does not effect the actual desc
                          // can be a const method
  p.print();              // const method, simply prints string
  return EXIT_SUCCESS;
}
