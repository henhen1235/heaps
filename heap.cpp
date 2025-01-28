#include <iostream>
#include <cstring>
#include "heap.h"

heap::heap(){
  position = 1;
  heap = new array[100];
}

heap::~heap(){
}

void heap::add(int value){
  if (position => 100){
    cout << "you are out of bounds";
  }
  else{
    heap[position] = value;
    int nPosition = position;
    while(nPosition != 1 && heap[nPosition] > heap[floor(nPosition / 2)]){
      int p1 = heap[nPosition];
      int p2 = heap[floor(nPosition / 2)];
      heap[nPosition] = p2;
      heap[floor(nPosition / 2)] = p1;
      nPosition = floor(nPosition / 2);
    }
   position = position + 1;
  }
}

int heap::removelargest(){
  int p1 = heap[1];
  heap[1] = heap[position];
  heap[position] = NULL;
  position = position - 1;
  int start = 1 
    while(start * 2 < position){
      int larger = 0; 
      if(heap[start] < heap[start * 2]){
	larger = start * 2;
      }
      if(heap[start] < heap[start * 2 + 1]){
	larger = start * 2 + 1;
      }
      if(larger == 0){
	break;
      }
      int p3 = heap[start];
      int p4 = heap[larger];
      heap[nPosition] = p2;
      heap[floor(nPosition / 2)] = p1;
      start = start *2;
    }  
  return p1;
}

void heap::removeall(){
  while(position > 1){
    removelargest();
  }
}

void heap::display(){
  if (position = 1) {
    return;
  }
  int depth = 0;
  int start = 1;
  displayrunner(start, depth, position);
}

void heap::displayrunner(int tempposition, int times, int size){
  if(tempposition * 2 + 1 < size){
    displayrunner(tempposition * 2 + 1, depth + 1, size);
  }
  for(int x = 0; x < depth; x++){
    cout << '\t';
  }
  cout << heaps[tempposition] << endl;
  if(tempposition * 2 < size){
    displayrunner(tempposition *2, depth +1,size)
  }
}
