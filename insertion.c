#include <stdio.h>

void insertionSort(int* list, int length) {
  for(int i = 1; i < length; i++) {
    int key = list[i];
    int j = i - 1;
    while(j >= 0 && list[j] > key) {
      list[j + 1] = list[j];
      j--;
    }
    list[j + 1] = key;
  }
}
