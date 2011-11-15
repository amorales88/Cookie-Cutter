#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>
#include "funcs.h"

using namespace std;


int main (int argc, char *argv[ ])
{

  //the values that we get from the 
  //command line will be put into these
  //variables. we can use them later in the program
  //like for checking if they have valid values
  int cache_capacity = 0;
  int cache_blocksize = 0;
  int cache_associativity = 0;
  int num_blocks = 0;
  int tag_size = 0;
  int data_size = 0;
  int miss_rate = 0;
  int hit_rate = 0;

  if(!parseParams(argc, argv, cache_capacity, cache_blocksize, cache_associativity)) {
	  exit(2);
  }
  
  cout << "Cache Capacity: " << cache_capacity << endl;
  cout << "Cache BlockSize: " << cache_blocksize << endl;
  cout << "Cache Associativity: " << cache_associativity << endl;
  
  num_blocks = (cache_capacity * 1024) / cache_blocksize;
  //TODO 
  int cache[num_blocks][cache_blocksize];
  
  for (int i = 0; i < num_blocks; i++) {
    for (int j = 0; j < cache_blocksize; j++) {
      cache[i][j] = 0;
    }
  }
}

