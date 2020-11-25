#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_SM 100
#define SIZE_MD 1000
#define SIZE_LG 100000
#define SIZE_XLG 1000000
#define SIZE_XXLG 10000000

int main(void) {
  int array_sm[SIZE_SM];
  int array_md[SIZE_MD];
  int array_lg[SIZE_LG];
  int array_xlg[SIZE_XLG];
  int array_xxlg[SIZE_XXLG];

  // declaring - crescent order
  for(int i = 0; i < SIZE_SM; i++) {
    array_sm[i] = i;
    array_md[i] = i;
    array_lg[i] = i;
    array_xlg[i] = i;
    array_xxlg[i] = i;
  }
  for(int i = SIZE_SM; i < SIZE_MD; i++) {
    array_md[i] = i;
    array_lg[i] = i;
    array_xlg[i] = i;
    array_xxlg[i] = i;
  }
  for(int i = SIZE_MD; i < SIZE_LG; i++) {
    array_lg[i] = i;
    array_xlg[i] = i;
    array_xxlg[i] = i;
  }
  for(int i = SIZE_LG; i < SIZE_XLG; i++) {
    array_xlg[i] = i;
    array_xxlg[i] = i;
  }
  for(int i = SIZE_XLG; i < SIZE_XXLG; i++) {
    array_xxlg[i] = i;
  }

  // declaring - decrescent order
  for(int i = SIZE_XXLG - 1; i >= SIZE_XLG; i--) {
    array_xxlg[i] = i;
  }
  for(int i = SIZE_XLG - 1; i >= SIZE_LG; i--) {
    array_xlg[i] = i;
    array_xxlg[i] = i;
  }
  for(int i = SIZE_LG - 1; i >= SIZE_MD; i--) {
    array_lg[i] = i;
    array_xlg[i] = i;
    array_xxlg[i] = i;
  }
  for(int i = SIZE_MD - 1; i >= SIZE_SM; i--) {
    array_md[i] = i;
    array_lg[i] = i;
    array_xlg[i] = i;
    array_xxlg[i] = i;
  }
  for(int i = SIZE_SM - 1; i >= 0; i--) {
    array_sm[i] = i;
    array_md[i] = i;
    array_lg[i] = i;
    array_xlg[i] = i;
    array_xxlg[i] = i;
  }

  // declaring - random
  srand(time(NULL));

  for(int i = 0; i < SIZE_SM; i++) {
    int num = rand() % SIZE_XXLG;
    array_sm[i] = num;
    array_md[i] = num;
    array_lg[i] = num;
    array_xlg[i] = num;
    array_xxlg[i] = num;
  }
  for(int i = SIZE_SM; i < SIZE_MD; i++) {
    int num = rand() % SIZE_XXLG;
    array_md[i] = num;
    array_lg[i] = num;
    array_xlg[i] = num;
    array_xxlg[i] = num;
  }
  for(int i = SIZE_MD; i < SIZE_LG; i++) {
    int num = rand() % SIZE_XXLG;
    array_lg[i] = num;
    array_xlg[i] = num;
    array_xxlg[i] = num;
  }
  for(int i = SIZE_LG; i < SIZE_XLG; i++) {
    int num = rand() % SIZE_XXLG;
    array_xlg[i] = num;
    array_xxlg[i] = num;
  }
  for(int i = SIZE_XLG; i < SIZE_XXLG; i++) {
    int num = rand() % SIZE_XXLG;
    array_xxlg[i] = num;
  }
 
  return 0;
}