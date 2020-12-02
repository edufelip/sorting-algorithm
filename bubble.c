#include <stdio.h>

void bubbleSort (long int* list, int size) {
  long k, j, aux;
  for (k = 0; k < size - 1; k++) {
    int check = 0;
    for (j = 0; j < size - k - 1; j++) {
      if (list[j] > list[j + 1]) {
        aux = list[j];
        list[j] = list[j + 1];
        list[j + 1] = aux;
        check = 1;
      }
    }
    if(!check) return;
  }
}