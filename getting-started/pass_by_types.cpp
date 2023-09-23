#include <iostream>

using namespace std;

void pass_by_value(int id, string name);
void pass_by_pointer(int *id, string *name);
void pass_by_reference(int &id, string &name);

int main(int argc, char **argv) {
  int id1 = 0xCAFE;
  string name1 = "Sumeet";
  cout << id1 << ", " << name1 << endl;
  pass_by_value(id1, name1);
  cout << id1 << ", " << name1 << endl;

  int id2 = 0xCAFE;
  string name2 = "Sumeet";
  cout << id2 << ", " << name2 << endl;
  pass_by_pointer(&id2, &name2);
  cout << id2 << ", " << name2 << endl;

  int id3 = 0xCAFE;
  string name3 = "Sumeet";
  cout << id3 << ", " << name3 << endl;
  pass_by_reference(id3, name3);
  cout << id3 << ", " << name3 << endl;

  string null_string = NULL;
  pass_by_reference(id3, null_string);  // cause segfault
  return EXIT_SUCCESS;
}

void pass_by_value(int id, string name) {
  id = 0xFAB;
  name = "Sarkar (pass by value)";
}

void pass_by_pointer(int *id, string *name) {
  *id = 0xFAB;
  *name = "Sarkar (pass by pointer)";
}

void pass_by_reference(int &id, string &name) {
  id = 0xFAB;
  name = "Sarkar (pass by ref)";
}
