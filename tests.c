#include <stdio.h>
#include <stdlib.h>
#include "insertion.c"

int main() {
  int *num;
  int length;
  printf("Insert the length\n");
  scanf("%d", &length);
  num = (int *) malloc(length*sizeof(int));
  if (num == NULL) { printf("Lacks memory\n"); exit(1); }
  printf("Insert the numbers\n");
  for(int i = 0; i < length; i++){
    scanf("%d", &num[i]);
  }
  insertion(num, length);
  printf("----------\n");
  for(int i = 0; i < length; i++){
    printf("%d\n", num[i]);
  }
  free(num);
  return 0;
}
