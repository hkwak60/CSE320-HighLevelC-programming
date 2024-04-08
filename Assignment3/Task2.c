#include <stdio.h>
#include <stdlib.h>

#define ROWS_A 9
#define COLS_A 8
#define ROWS_B 8
#define COLS_B 9

void matrix_multiply(int *A, int *B, int **C) {
  for (int i = 0; i < ROWS_A; i++) {
    for (int j = 0; j < COLS_B; j++) {
      // Initialize the result matrix element to 0
      C[i][j]=0;
      for (int k = 0; k < COLS_A; k++) {
        // Perform matrix multiplication
        // matC[i][j]+=A[i][k]*B[k][j];
        C[i][j]+=(*(A+COLS_A*i+k))*(*(B+COLS_B*k+j));
      }
    }
  }
}

int main() {
  int matA[ROWS_A][COLS_A] = {
  {1, 2, 3, 4, 5, 6, 7, 8},
  {2, 3, 4, 5, 6, 7, 8, 9},
  {3, 4, 5, 6, 7, 8, 9, 1},
  {4, 5, 6, 7, 8, 9, 1, 2},
  {5, 6, 7, 8, 9, 1, 2, 3},
  {6, 7, 8, 9, 1, 2, 3, 4},
  {7, 8, 9, 1, 2, 3, 4, 5},
  {8, 9, 1, 2, 3, 4, 5, 6},
  {9, 1, 2, 3, 4, 5, 6, 7},
  };
  int matB[ROWS_B][COLS_B] = {
  {1, 2, 3, 4, 5, 6, 7, 8, 9},
  {2, 3, 4, 5, 6, 7, 8, 9, 1},
  {3, 4, 5, 6, 7, 8, 9, 1, 2},
  {4, 5, 6, 7, 8, 9, 1, 2, 3},
  {5, 6, 7, 8, 9, 1, 2, 3, 4},
  {6, 7, 8, 9, 1, 2, 3, 4, 5},
  {7, 8, 9, 1, 2, 3, 4, 5, 6},
  {8, 9, 1, 2, 3, 4, 5, 6, 7},
  };
  int **matOut;
  matOut= malloc(sizeof(int*)*ROWS_A);                   
  for(int i =0 ;i <ROWS_A;i++)                           
    matOut[i]=malloc(sizeof(int)*COLS_B);                 
  // Multiply matrices matA and matB
  matrix_multiply(&matA[0][0],&matB[0][0],matOut);
  // Print the result of the matrix multiplication
  for(int i = 0; i<ROWS_A;i++){
    for(int j = 0; j<COLS_B;j++)
      printf("%d ",matOut[i][j]);
    printf("\n");
  }


  for(int i = 0;i<ROWS_A;i++){
    free(matOut[i]);
  }
  free(matOut);
  return 0;
}