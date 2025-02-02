#include <iostream>
#include "heap.h"
#include <cstring>
#include <fstream>
#include <vector>


using namespace std;

int main(){
  heap* heaps = new heap;
  while(true){
    cout << "What would you like to do?" << endl;
    char input[50];
    char print[50] = "print";
    char add[50] = "add";
    char addfile[50] = "addfile";
    char remove[50] = "remove";
    char destroy[50] = "destroy";
    char quit[50] = "quit";
    cin >> input;
    if (strcmp(input, add) == 0){//add whatever the user wants to add
      cout << "Please enter an number" << endl;
      int num;
      cin >> num;
      heaps->add(num);
    }
    else if (strcmp(input, addfile) == 0){//print out heap
      cout << "Please type file name" << endl;
      string name;
      cin >> name;
      string txt = ".txt";
      ifstream inputFile(name + txt);
      int num;
      while (inputFile >> num) {
        heaps->add(num);
      }
      inputFile.close();
    }
    else if (strcmp(input, print) == 0){//print out heap
      heaps->display();
    }
    else if (strcmp(input, remove) == 0){//remove largest then print out
      int largest = heaps->removelargest();
      cout << largest << endl;
    }
    else if (strcmp(input, destroy) == 0){//destory enttire heap
      while(heaps->position != 1){
        int largest = heaps->removelargest();
        cout << largest << endl;
      }
    }
    else if (strcmp(input, quit) == 0){//quitting
      delete heaps;
      break;
    }
    else{
     cout << "Your input was not valid your options are: add, addfile, print, remove, destory, quit.";//their command isn't valid
        }
  }
  return 0;
}
