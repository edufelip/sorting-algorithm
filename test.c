#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "selection.c"
#include "insertion.c"
#include "bubble.c"
#include "quick.c"
#include "merge.c"

int main(void) {
  int SIZE_SM = 100;
  long SIZE_MD = 1000;
  long SIZE_LG = 100000;
  long SIZE_XLG = 1000000;
  long SIZE_XXLG = 10000000;

  long* array_sm = (long*)calloc(SIZE_SM, sizeof(long));
  long* array_test_sm = (long*)calloc(SIZE_SM, sizeof(long));
  long* array_md = (long*)calloc(SIZE_MD, sizeof(long));
  long* array_test_md = (long*)calloc(SIZE_MD, sizeof(long));
  long* array_lg = (long*)calloc(SIZE_LG, sizeof(long));
  long* array_test_lg = (long*)calloc(SIZE_LG, sizeof(long));
  long* array_xlg = (long*)calloc(SIZE_XLG, sizeof(long));
  long* array_test_xlg = (long*)calloc(SIZE_XLG, sizeof(long));
  long* array_xxlg = (long*)calloc(SIZE_XXLG, sizeof(long));
  long* array_test_xxlg = (long*)calloc(SIZE_XXLG, sizeof(long));

  double time_taken;
  struct timeval start, end;

  for(int p = 2; p < 3; p++) {
    if(p == 0) {
      printf("[[[ CRESCENT ORDER ]]]\n");
      for(long i = 0; i < SIZE_SM; i++) {
        array_sm[i] = i;
        array_test_sm[i] = i;
        array_md[i] = i;
        array_test_md[i] = i;
        array_lg[i] = i;
        array_test_lg[i] = i;
        array_xlg[i] = i;
        array_test_xlg[i] = i;
        array_xxlg[i] = i;
        array_test_xxlg[i] = i;
      }
      for(long i = SIZE_SM; i < SIZE_MD; i++) {
        array_md[i] = i;
        array_test_md[i] = i;
        array_lg[i] = i;
        array_test_lg[i] = i;
        array_xlg[i] = i;
        array_test_xlg[i] = i;
        array_xxlg[i] = i;
        array_test_xxlg[i] = i;
      }
      for(long i = SIZE_MD; i < SIZE_LG; i++) {
        array_lg[i] = i;
        array_test_lg[i] = i;
        array_xlg[i] = i;
        array_test_xlg[i] = i;
        array_xxlg[i] = i;
        array_test_xxlg[i] = i;
      }
      for(long i = SIZE_LG; i < SIZE_XLG; i++) {
        array_xlg[i] = i;
        array_test_xlg[i] = i;
        array_xxlg[i] = i;
        array_test_xxlg[i] = i;
      }
      for(long i = SIZE_XLG; i < SIZE_XXLG; i++) {
        array_xxlg[i] = i;
        array_test_xxlg[i] = i;
      }
    } else if (p == 1) {
      printf("[[[ DECRESCENT ORDER ]]]\n");
      long sup = 0;
      for(long i = SIZE_XXLG - 1; i >= SIZE_XLG; i--) {
        array_xxlg[i] = sup;
        array_test_xxlg[i] = sup;
        sup++;
      }
      for(long i = SIZE_XLG - 1; i >= SIZE_LG; i--) {
        array_xlg[i] = sup;
        array_test_xlg[i] = sup;
        array_xxlg[i] = sup;
        array_test_xxlg[i] = sup;
        sup++;
      }
      for(long i = SIZE_LG - 1; i >= SIZE_MD; i--) {
        array_lg[i] = sup;
        array_test_lg[i] = sup;
        array_xlg[i] = sup;
        array_test_xlg[i] = sup;
        array_xxlg[i] = sup;
        array_test_xxlg[i] = sup;
        sup++;
      }
      for(long i = SIZE_MD - 1; i >= SIZE_SM; i--) {
        array_md[i] = sup;
        array_test_md[i] = sup;
        array_lg[i] = sup;
        array_test_lg[i] = sup;
        array_xlg[i] = sup;
        array_test_xlg[i] = sup;
        array_xxlg[i] = sup;
        array_test_xxlg[i] = sup;
        sup++;
      }
      for(long i = SIZE_SM - 1; i >= 0; i--) {
        array_sm[i] = sup;
        array_test_sm[i] = sup;
        array_md[i] = sup;
        array_test_md[i] = sup;
        array_lg[i] = sup;
        array_test_lg[i] = sup;
        array_xlg[i] = sup;
        array_test_xlg[i] = sup;
        array_xxlg[i] = sup;
        array_test_xxlg[i] = sup;
        sup++;
      }
    } else if (p == 2) {
      printf("[[[ RANDOM ORDER ]]]\n");
      srand(time(NULL));
      for(long i = 0; i < SIZE_SM; i++) {
        long num = rand() % SIZE_XXLG;
        array_sm[i] = num;
        array_test_sm[i] = num;
        array_md[i] = num;
        array_test_md[i] = num;
        array_lg[i] = num;
        array_test_lg[i] = num;
        array_xlg[i] = num;
        array_test_xlg[i] = num;
        array_xxlg[i] = num;
        array_test_xxlg[i] = num;
      }
      for(long i = SIZE_SM; i < SIZE_MD; i++) {
        long num = rand() % SIZE_XXLG;
        array_md[i] = num;
        array_test_md[i] = num;
        array_lg[i] = num;
        array_test_lg[i] = num;
        array_xlg[i] = num;
        array_test_xlg[i] = num;
        array_xxlg[i] = num;
        array_test_xxlg[i] = num;
      }
      for(long i = SIZE_MD; i < SIZE_LG; i++) {
        long num = rand() % SIZE_XXLG;
        array_lg[i] = num;
        array_test_lg[i] = num;
        array_xlg[i] = num;
        array_test_xlg[i] = num;
        array_xxlg[i] = num;
        array_test_xxlg[i] = num;
      }
      for(long i = SIZE_LG; i < SIZE_XLG; i++) {
        long num = rand() % SIZE_XXLG;
        array_xlg[i] = num;
        array_test_xlg[i] = num;
        array_xxlg[i] = num;
        array_test_xxlg[i] = num;
      }
      for(long i = SIZE_XLG; i < SIZE_XXLG; i++) {
        long num = rand() % SIZE_XXLG;
        array_xxlg[i] = num;
        array_test_xxlg[i] = num;
      }
    }

    printf("TESTING ARRAY SM ------\n");
    for(int i = 0; i < 5; i++) {
      gettimeofday(&start, NULL);
      if(i == 0) {
        insertionSort(array_test_sm, SIZE_SM);
      } else if (i == 1) {
        bubbleSort(array_test_sm, SIZE_SM);
      } else if (i == 2) {
        selectionSort(array_test_sm, SIZE_SM);
      } else if (i == 3) {
        quickSort(array_test_sm, 0, SIZE_SM - 1);     
      } else if (i == 4) {
        mergeSort(array_test_sm, 0, SIZE_SM - 1);
      }
      gettimeofday(&end, NULL);
      time_taken = end.tv_sec + end.tv_usec / 1e6 - start.tv_sec - start.tv_usec / 1e6;

      for (int j = 0; j < SIZE_SM; j++) {
        array_test_sm[j] = array_sm[j];
      }

      if(i == 0) {
        printf("InsertionSort took %.10lf seconds\n", time_taken);
      } else if (i == 1) {
        printf("BubbleSort took %.10lf seconds\n", time_taken);
      } else if (i == 2) {
        printf("SelectionSort took %.10lf seconds\n", time_taken);
      } else if (i == 3) {
        printf("QuickSort took %.10lf seconds\n", time_taken);
      } else if (i == 4) {
        printf("MergeSort took %.10lf seconds\n", time_taken);
      }
    }
    printf("------------\n");

    printf("TESTING ARRAY MD ------\n");
    for(int i = 0; i < 5; i++) {
      gettimeofday(&start, NULL);
      if(i == 0) {
        insertionSort(array_test_md, SIZE_MD);
      } else if (i == 1) {
        bubbleSort(array_test_md, SIZE_MD);
      } else if (i == 2) {
        selectionSort(array_test_md, SIZE_MD);
      } else if (i == 3) {
        quickSort(array_test_md, 0, SIZE_MD - 1);     
      } else if (i == 4) {
        mergeSort(array_test_md, 0, SIZE_MD - 1);
      }
      gettimeofday(&end, NULL);
      time_taken = end.tv_sec + end.tv_usec / 1e6 - start.tv_sec - start.tv_usec / 1e6;
      
      for (int j = 0; j < SIZE_MD; j++) {
        array_test_md[j] = array_md[j];
      }

      if(i == 0) {
        printf("InsertionSort took %.10lf seconds\n", time_taken);
      } else if (i == 1) {
        printf("BubbleSort took %.10lf seconds\n", time_taken);
      } else if (i == 2) {
        printf("SelectionSort took %.10lf seconds\n", time_taken);
      } else if (i == 3) {
        printf("QuickSort took %.10lf seconds\n", time_taken);
      } else if (i == 4) {
        printf("MergeSort took %.10lf seconds\n", time_taken);
      }
    }
    printf("------------\n");
    printf("TESTING ARRAY LG ------\n");
    for(int i = 0; i < 5; i++) {
      gettimeofday(&start, NULL);
      if(i == 0) {
        insertionSort(array_test_lg, SIZE_LG);
      } else if (i == 1) {
        bubbleSort(array_test_lg, SIZE_LG);
      } else if (i == 2) {
        selectionSort(array_test_lg, SIZE_LG);
      } else if (i == 3) {
        quickSort(array_test_lg, 0, SIZE_LG - 1);     
      } else if (i == 4) {
        mergeSort(array_test_lg, 0, SIZE_LG - 1);
      }
      gettimeofday(&end, NULL);
      time_taken = end.tv_sec + end.tv_usec / 1e6 - start.tv_sec - start.tv_usec / 1e6;
      
      for (long int j = 0; j < SIZE_LG; j++) {
        array_test_lg[j] = array_lg[j];
      }

      if(i == 0) {
        printf("InsertionSort took %.10lf seconds\n", time_taken);
      } else if (i == 1) {
        printf("BubbleSort took %.10lf seconds\n", time_taken);
      } else if (i == 2) {
        printf("SelectionSort took %.10lf seconds\n", time_taken);
      } else if (i == 3) {
        printf("QuickSort took %.10lf seconds\n", time_taken);
      } else if (i == 4) {
        printf("MergeSort took %.10lf seconds\n", time_taken);
      }
    }
    printf("------------\n");
    printf("TESTING ARRAY XLG ------\n");
    for(int i = 0; i < 5; i++) {
      gettimeofday(&start, NULL);
      if(i == 0) {
        insertionSort(array_test_xlg, SIZE_XLG);
      } else if (i == 1) {
        bubbleSort(array_test_xlg, SIZE_XLG);
      } else if (i == 2) {
        selectionSort(array_test_xlg, SIZE_XLG);
      } else if (i == 3) {
        quickSort(array_test_xlg, 0, SIZE_XLG - 1);     
      } else if (i == 4) {
        mergeSort(array_test_xlg, 0, SIZE_XLG - 1);
      }
      gettimeofday(&end, NULL);
      time_taken = end.tv_sec + end.tv_usec / 1e6 - start.tv_sec - start.tv_usec / 1e6;
      
      for (long j = 0; j < SIZE_XLG; j++) {
        array_test_xlg[j] = array_xlg[j];
      }

      if(i == 0) {
        printf("InsertionSort took %.10lf seconds\n", time_taken);
      } else if (i == 1) {
        printf("BubbleSort took %.10lf seconds\n", time_taken);
      } else if (i == 2) {
        printf("SelectionSort took %.10lf seconds\n", time_taken);
      } else if (i == 3) {
        printf("QuickSort took %.10lf seconds\n", time_taken);
      } else if (i == 4) {
        printf("MergeSort took %.10lf seconds\n", time_taken);
      }
    }
    printf("------------\n");
    printf("TESTING ARRAY XXLG ------\n");
    for(int i = 0; i < 5; i++) {
      gettimeofday(&start, NULL);
      if(i == 0) {
        // insertionSort(array_test_xxlg, SIZE_XXLG);
      } else if (i == 1) {
        // bubbleSort(array_test_xxlg, SIZE_XXLG);
      } else if (i == 2) {
        // selectionSort(array_test_xxlg, SIZE_XXLG);
      } else if (i == 3) {
        quickSort(array_test_xxlg, 0, SIZE_XXLG - 1);     
      } else if (i == 4) {
        mergeSort(array_test_xxlg, 0, SIZE_XXLG - 1);
      }
      gettimeofday(&end, NULL);
      time_taken = end.tv_sec + end.tv_usec / 1e6 - start.tv_sec - start.tv_usec / 1e6;
      
      for (long j = 0; j < SIZE_XXLG; j++) {
        array_test_xxlg[j] = array_xxlg[j];
      }

      if(i == 0) {
        // printf("InsertionSort took %.10lf seconds\n", time_taken);
      } else if (i == 1) {
        // printf("BubbleSort took %.10lf seconds\n", time_taken);
      } else if (i == 2) {
        // printf("SelectionSort took %.10lf seconds\n", time_taken);
      } else if (i == 3) {
        printf("QuickSort took %.10lf seconds\n", time_taken);
      } else if (i == 4) {
        printf("MergeSort took %.10lf seconds\n", time_taken);
      }
    }
  }

  free(array_sm);
  free(array_test_sm);
  free(array_md);
  free(array_test_md);
  free(array_lg);
  free(array_test_lg);
  free(array_xlg);
  free(array_test_xlg);
  free(array_xxlg);
  free(array_test_xxlg);
  return 0;
}
