#include <stdio.h>
#include <stdlib.h>

#define ROWS_A 50
#define COLS_A 70
#define ROWS_B 70
#define COLS_B 50

void matrix_multiply1(int **A, int **B, int **C) {
  for (int i = 0; i < ROWS_A; i++) {
    for (int j = 0; j < COLS_B; j++) {
      // Initialize the result matrix element to 0
      C[i][j]=0;
      for (int k = 0; k < COLS_A; k++) {
        // Perform matrix multiplication
        // C[i][j]+=A[i][k]*B[k][j];
        C[i][j]+=A[i][k]*B[k][j];
      }
    }
  }
}

int main() {
  FILE *inFile;
  FILE *outFile;
  int **matA;
  int **matB;
  int **matOut;
  // Allocate memory for matA, matB, and matOut
  matOut = (int**)malloc(sizeof(int*)*ROWS_A);
  for(int i =0 ;i <ROWS_A;i++)
    matOut[i]=(int*)malloc(sizeof(int)*COLS_B);
  
  matA = (int**)malloc(sizeof(int*)*ROWS_A);
  for(int i =0 ;i <ROWS_A;i++)
    matA[i]=(int*)malloc(sizeof(int)*COLS_A);

  matB = (int**)malloc(sizeof(int*)*ROWS_B);
  for(int i =0 ;i <ROWS_B;i++)
    matB[i]=(int*)malloc(sizeof(int)*COLS_B);

  // Open the file for reading and load integers to matA and matB
  inFile = fopen("matrices.txt","r");
  for(int i = 0; i<ROWS_A;i++){
    for(int j = 0; j<COLS_A;j++){
      fscanf(inFile, "%d ",&matA[i][j]);
    }
  }

  for(int i = 0; i<ROWS_B;i++){
    for(int j = 0; j<COLS_B;j++){
      fscanf(inFile, "%d ",&matB[i][j]);
    }
  }

  // Multiply matrices matA and matB
  matrix_multiply1(matA,matB,matOut);
  // Write the result of the matrix multiplication
  outFile = fopen("output.txt", "w+");
  for(int i = 0; i<ROWS_A;i++){
    for(int j = 0; j<COLS_B;j++){
      fprintf(outFile,"%d ", matOut[i][j]);
    }
    fprintf(outFile,"\n");
  }

  // Free the dynamically allocated memories
  
  for(int i =0 ;i <ROWS_A;i++){
    free(matOut[i]);
    free(matA[i]);
  }
  free(matOut);
  free(matA);

  for(int i =0 ;i <ROWS_B;i++){
    free(matB[i]);
  }
  free(matB);


  //Close the file
  fclose(inFile);
  fclose(outFile);
  printf("\t<output.txt generated>\n");
  return 0;
}