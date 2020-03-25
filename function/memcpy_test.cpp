#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

void example(volatile int *a, volatile int *b){
  

  int i;
  int buff[10];
  
  //memcpy creates a burst access to memory
  //multiple calls of memcpy cannot be pipelined and will be scheduled sequentially
  //memcpy requires a local buffer to store the results of the memory transaction
  memcpy(buff,(const int*)a, 5*sizeof(int));
  memcpy(buff + 5,(const int*)(a + 5),5*sizeof(int));
  
  for(i=0; i < 10; i++){
    buff[i] = buff[i] + 100;
  }
  
  memcpy((int *)b, buff + 0, 5*sizeof(int));
  memcpy((int *)(b + 5), buff + 5, 5*sizeof(int));
}

int main () {
	int a[10];
	int b[10];
	for (int i = 0; i < 10; i ++) {
		a[i] = i * 2;
	}
	/*	
	for (int i = 0; i < 5; i ++) {
		cout<<*(a + 5 + i) <<endl;
	}	
	*/
	example (a, b);
	for (int i = 0; i < 10; i ++) {
		cout<<b[i]<<endl;
	}
	return 0;
}
