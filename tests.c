#include <stdio.h>
#include "selection.c"

int main() {
  int num[4] = {9, 0, 9, 0};
  int length = sizeof(num)/sizeof(int);
  selection(num, length);
  for(int i = 0; i < length; i++){
    printf("%d\n", num[i]);
  }
  return 0;
}
