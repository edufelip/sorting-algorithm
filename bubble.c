#include <stdio.h>

void bubble(int* list, int size) {
  int i, j, temp;
  for(i = size - 1; i > 0; i--) {
    int troca = 0;
    for(j = 0; j < size - 1; j++) {
      if (list[j] > list[j+1]) {
        temp = list[j+1];
        list[j+1] = list[j];
        list[j] = temp;
        troca = 1;
      }
    }
    if(troca == 0) return;
  }
  
}