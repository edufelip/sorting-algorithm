#include <stdio.h>

void quickSort(long int* list, int start, int end) {
  int i = start;
  int j = end;
  int x = list[(start + end) / 2];
  int y;

  while(i <= j) {
    while(list[i] < x && i < end) {
        i++;
    }
    while(list[j] > x && j > start) {
        j--;
    }
    if(i <= j) {
        y = list[i];
        list[i] = list[j];
        list[j] = y;
        i++;
        j--;
    }
  }
  if(j > start) {
    quickSort(list, start, j);
  }
  if(i < end) {
    quickSort(list, i, end);
  }
}