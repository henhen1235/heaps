#include <iostream>
#include <vector>

using namespace std;

class heap{
 public:
  heap();
  ~heap();
  void add(int value);
  int removelargest();
  void removeall();
  void display();
  void displayrunner(int tempposition, int depth, int size);
 public:
  int position;
  int* heapar;
};
