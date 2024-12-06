#include <iostream>
#include <vector>

class heap {
 public:
  void add(int value);
  int removelargest();
  void removeall();
  void display();
 public:
  int position;
  int* heap;
};
