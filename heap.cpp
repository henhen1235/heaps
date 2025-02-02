#include <iostream>
#include "heap.h"
#include <cstring>
#include <math.h> 
//imports
using namespace std;

heap::heap(){//make the heap
  position = 1;
  heapar = new int[100];
  for(int x = 0; x < 100; x++) {
     heapar[x] = 0; // Initialize all elements to 0
  }
}

heap::~heap(){//remove the heap
  delete[] heapar;
}

void heap::add(int value){//adding new
  if (position >= 100){
    cout << "you are out of bounds";
  }
  else{
    heapar[position] = value;// replace with the node above it if the current node is bigger
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

int heap::removelargest(){// remove largest
  if (position == 1){
    cout << "There are no nodes" << endl;
    return 0;
  }
  int largest = heapar[1];// get rid of largest and most latest node there
  int p1 = heapar[position];
  heapar[1] = p1;
  heapar[position] = 0;
  position = position - 1;
  int start = 1; 
  while (true){
    int left = start * 2;
    int right = start * 2 +1;
    int larger = start;

    if (left < position && heapar[left] > heapar[larger]){//if left is larger
      larger = left;
    }
    
    if (right < position && heapar[right] > heapar[larger]){// if right is larger
      larger = right;
    }

    if (larger == start){
      break;// if both are smaller
    }
    int tempsmaller = heapar[start];
    int templarger = heapar[larger];//swap
    heapar[start] = templarger;
    heapar[larger] = tempsmaller;
    start = larger;
  }

// this is an implementation method that I tried that did not work. Instead I just went back to what I was trying to do that the start and it worked.
  // while(heapar[start * 2] != 0){
  //   if(heapar[start * 2 + 1] == 0){
  //     if(heapar[start] < heapar[start * 2]){
	//  int templarge = heapar[start * 2];
  //        int tempsmall = heapar[start];
  //        heapar[start] = templarge;
  //        heapar[start * 2] = tempsmall;
  //        start = start * 2;
	//  break;
  //     }
  //   }
  //   else{
  //       if(heapar[start * 2 + 1] < heapar[start * 2]){
  //         int templarge = heapar[start * 2]; 
  //         int tempsmall = heapar[start];
  //         heapar[start] = templarge;
  //         heapar[start * 2] = tempsmall;
  //         start = start * 2;
  //       }
	// else if(heapar[start * 2 + 1] > heapar[start * 2]){
  //         int templarge = heapar[start * 2 + 1];
  //         int tempsmall = heapar[start];
  //         heapar[start] = templarge;
  //         heapar[start * 2 + 1] = tempsmall;
  //         start = start * 2 + 1;
	// }
	// else{
	//   if(heapar[start * 2 + 1] < heapar[start * 2]){
  //         int templarge = heapar[start * 2]; 
  //         int tempsmall = heapar[start];
  //         heapar[start] = templarge;
  //         heapar[start * 2] = tempsmall;
  //         start = start * 2;
  //       }
	// }
  //   }
  //   }  
  return largest;
}

void heap::removeall(){//run remove largest over and over until there is non left
  while(position > 1){
    removelargest();
  }
}

void heap::display(){//diplay everything
  if (position == 1) {
    return;
  }
  int depth = 0;
  int start = 1;
  displayrunner(start, depth, position);
}

void heap::displayrunner(int tempposition, int depth, int size){// display runner function
  if(tempposition >= size || heapar[tempposition] == 0){
    return;
  }
  if(tempposition * 2 + 1 < size && heapar[tempposition] != 0){//go down the right nodes
    displayrunner(tempposition * 2 + 1, depth + 1, size);
  }
  for(int x = 0; x < depth; x++){//orint
    cout << '\t';
  }
  cout << heapar[tempposition] << endl;
  if(tempposition * 2 < size && heapar[tempposition] != 0){//go down the left nodes
    displayrunner(tempposition *2, depth +1,size);
  }
}
