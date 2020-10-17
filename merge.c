#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * slice(int * list, int size, int start, int end) {
  int* sideList = (int *) malloc(size*sizeof(int));
  int j = 0;
  for(int i = start; i <= end; i++){
    sideList[j] = list[i];
    j++;
  }
  return sideList;
}

int * merge(int * list, int start, int middle, int end) {
  int leftListSize = middle - start;
  int rightListSize = end - middle + 1;
  int* leftList = slice(list, leftListSize, start, middle - 1);
  int* rightList = slice(list, rightListSize, middle, end);
  int i = 0, j = 0;
  for(int k = start; k <= end; k++) {
    if(i >= leftListSize) {
      list[k] = rightList[j];
      j++;
    } else if(j >= rightListSize) {
      list[k] = leftList[i];
      i++;
    } else if(leftList[i] < rightList[j]) {
      list[k] = leftList[i];
      i++;
    } else {
      list[k] = rightList[j];
      j++;
    }
  }
  printf("\n");
  free(leftList);
  free(rightList);
  return list;
}

void mergeSort(int* list, int start, int end) {
  if(end - start >= 1) {
    int middle = ceil((float)(end + start)/2);
    mergeSort(list, start, middle - 1);
    mergeSort(list, middle, end);
    merge(list, start, middle, end);
  }
}