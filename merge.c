#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long * slice(long * list, long size, long start, long end) {
  long* sideList = (long *) malloc(size*sizeof(long));
  long j = 0;
  for(long i = start; i <= end; i++){
    sideList[j] = list[i];
    j++;
  }
  return sideList;
}

long * merge(long * list, long start, long middle, long end) {
  long leftListSize = middle - start;
  long rightListSize = end - middle + 1;
  long* leftList = slice(list, leftListSize, start, middle - 1);
  long* rightList = slice(list, rightListSize, middle, end);
  long i = 0, j = 0;
  for(long k = start; k <= end; k++) {
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
  free(leftList);
  free(rightList);
  return list;
}

void mergeSort(long* list, long start, long end) {
  if(end - start >= 1) {
    long middle = ceil((long double)(end + start)/2);
    mergeSort(list, start, middle - 1);
    mergeSort(list, middle, end);
    merge(list, start, middle, end);
  }
}