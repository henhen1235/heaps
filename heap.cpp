#include <iostream>
#include "heap.h"
#include <cstring>
#include <math.h> 

using namespace std;

heap::heap(){
  position = 1;
  heapar = new int[100];
}

heap::~heap(){
  delete[] heapar;
}

void heap::add(int value){
  if (position >= 100){
    cout << "you are out of bounds";
  }
  else{
    heapar[position] = value;
    int nPosition = position;
    while(nPosition != 1 && heapar[nPosition] > heapar[nPosition / 2]){
      int p1 = heapar[nPosition];
      int p2 = heapar[nPosition / 2];
      heapar[nPosition] = p2;
      heapar[nPosition / 2] = p1;
      nPosition = floor(nPosition / 2);
    }
   position = position + 1;
  }
}

int heap::removelargest(){//__________________________________________________________________________broken
  if (position == 1){
    cout << "There are no nodes" << endl;
    return 0;
  }
  int largest = heapar[1];
  int p1 = heapar[position];
  heapar[1] = p1;
  heapar[position] = 0;
  position = position - 1;
  int start = 1; 
    while(start * 2 + 1 < position){
        if(heapar[start] < heapar[start * 2]){
          int templarge = heapar[start * 2]; 
          int tempsmall = heapar[start];
          heapar[start] = templarge;
          heapar[start * 2] = tempsmall;
          start = start * 2;
        }
        else if(heapar[start] < heapar[start * 2 + 1]){
          int templarge = heapar[start * 2 + 1]; 
          int tempsmall = heapar[start];
          heapar[start] = templarge;
          heapar[start * 2 + 1] = tempsmall;
          start = start * 2 + 1;
        }
        else{
          break;
        }
    }  
  return largest;
}

void heap::removeall(){
  while(position > 1){
    removelargest();
  }
}

void heap::display(){
  if (position == 1) {
    return;
  }
  int depth = 0;
  int start = 1;
  displayrunner(start, depth, position);
}

void heap::displayrunner(int tempposition, int depth, int size){
  if(tempposition * 2 + 1 < size){
    displayrunner(tempposition * 2 + 1, depth + 1, size);
  }
  for(int x = 0; x < depth; x++){
    cout << '\t';
  }
  cout << heapar[tempposition] << endl;
  if(tempposition * 2 < size){
    displayrunner(tempposition *2, depth +1,size);
  }
}
