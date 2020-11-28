#include <stdio.h>

void exchange(int* list, int i, int j) {
  int sup = list[i];
  list[i] = list[j];
  list[j] = sup;
}

int split(int* list, int left, int right) {
  int i = left + 1;
  int j = right;
  int pivot = list[left];
  while(i <= j) {
    if (list[i] <= pivot) {
      i++;
    } else if (list[j] > pivot) {
      j--;
    } else if (i <= j) {
      exchange(list, i, j);
      i++;
      j--;
    }
  }
  exchange(list, left, j);
  return j;
}

void quickSort(int* list, int start, int end) {
  if (start < end) {
    int j = split(list, start, end);
    quickSort(list, start, j - 1);
    quickSort(list, j + 1, end);
  }
}