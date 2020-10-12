#include <stdio.h>

void selection(int* list, int size) {
  int i, j, temp, menor;
  int aux;
  for(i = 0; i < size - 1; i++) {
    menor = i;
    for(j = i + 1; j < size; j++) {
      if (list[j] < list[menor]) {
        menor = j;
      }
    }
    aux = list[i];
    list[i] = list[menor];
    list[menor] = aux;
  }
}