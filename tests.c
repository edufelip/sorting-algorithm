#include <stdio.h>
#include <stdlib.h>
#include "merge.c"

int main() {
  int length;
  printf("Insert the length\n");
  scanf("%d", &length);

  int *list = (int *) malloc(length*sizeof(int));
  if (list == NULL) { printf("Lacks memory\n"); exit(1); }

  printf("Insert the numbers\n");
  for(int i = 0; i < length; i++){
    scanf("%d", &list[i]);
  }
  mergeSort(list, 0, length - 1);
  printf("----------\n");
  for(int i = 0; i < length; i++){
    printf("%d\n", list[i]);
  }
  free(list);
  return 0;
}
