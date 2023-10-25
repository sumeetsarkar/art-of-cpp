#include <cstdlib>
#include <iostream>

using namespace std;

class Animal {
  std::string name;

 public:
  std::string desc;

  Animal() { cout << "Animal created!" << endl; }
  void eat();
  virtual void sleep() = 0;
};

class Dog : public Animal {
 public:
  Dog() { cout << "Dog created!" << endl; }
  void eat() { cout << "a dog eats" << endl; }
  void sleep();
};

void Dog::sleep() { cout << "a dog sleeps" << endl; }

int main(int argc, char **argv) {
  Dog dog;
  dog.eat();
  dog.sleep();
  dog.desc = "Man's best friend";
  return EXIT_SUCCESS;
}
