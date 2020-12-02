#include <stdio.h>

void insertionSort(long* list, long length) {
  for(long i = 1; i < length; i++) {
    long key = list[i];
    long j = i - 1;
    while(j >= 0 && list[j] > key) {
      list[j + 1] = list[j];
      j--;
    }
    list[j + 1] = key;
  }
}
