#include <cstdlib>
#include <iostream>
#include <string>

class Person {
  long id;
  std::string fname;
  std::string lname;

 public:
  std::string to_string();

  Person() {}

  Person(long id, std::string fname, std::string lname) {
    set_id(id);
    set_fname(fname);
    set_lname(lname);
  }

  void set_id(long id) { this->id = id; }

  void set_fname(std::string fname) { this->fname = fname; }

  void set_lname(std::string lname) { this->lname = lname; }

  long get_id() { return this->id; }

  std::string get_fname() { return this->fname; }

  std::string get_lname() { return this->lname; }

  std::string get_name() { return get_fname() + " " + get_lname(); }
};

std::string Person::to_string() {
  return "{ id: " + std::to_string(get_id()) + ", f_name: " + get_fname() +
         ", l_name: " + get_lname() + " }";
}

int main(int argc, char **argv) {
  Person p1;
  p1.set_id(1001);
  p1.set_fname("John");
  p1.set_lname("Doe");

  std::cout << std::endl << p1.get_name() << std::endl;
  std::cout << p1.to_string();

  Person p2(1002, "Blake", "Harden");
  std::cout << std::endl << p2.get_name() << std::endl;
  std::cout << p2.to_string();

  std::cout << std::endl;
  return EXIT_SUCCESS;
}
