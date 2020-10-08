#include <stdio.h>
#include "bubble.c"

int main() {
  int num[4] = {9, 0, 9, 0};
  int length = sizeof(num)/sizeof(int);
  bubble(num, length);
  for(int i = 0; i < length; i++){
    printf("%d\n", num[i]);
  }
  return 0;
}
