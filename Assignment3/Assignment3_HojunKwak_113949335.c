#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS_A 9
#define COLS_A 8
#define ROWS_B 8
#define COLS_B 9

#define ROWS_A1 50
#define COLS_A1 70
#define ROWS_B1 70
#define COLS_B1 50

void matrix_multiply(int *A, int *B, int **C) {
  for (int i = 0; i < ROWS_A; i++) {
    for (int j = 0; j < COLS_B; j++) {
      // Initialize the result matrix element to 0
      C[i][j]=0;
      for (int k = 0; k < COLS_A; k++) {
        // Perform matrix multiplication
        // Basic algorithm: C[i][j]+=A[i][k]*B[k][j];
        C[i][j]+=(*(A+COLS_A*i+k))*(*(B+COLS_B*k+j));
      }
    }
  }
}

void matrix_multiply1(int **A, int **B, int **C) {
  for (int i = 0; i < ROWS_A1; i++) {
    for (int j = 0; j < COLS_B1; j++) {
      // Initialize the result matrix element to 0
      C[i][j]=0;
      for (int k = 0; k < COLS_A1; k++) {
        // Perform matrix multiplication
        // Basic algorithm: C[i][j]+=A[i][k]*B[k][j];
        C[i][j]+=A[i][k]*B[k][j];
      }
    }
  }
}

// Define a union named "Data" to hold different data types
union Data {
  int intData;
  double doubleData;
  char *stringData;
};
// Define a structure named "SNN" to represent a spiking neuron network
struct SNN {
  char *neuronName;
  int neuronNumber;
  union Data commonData;
};
// Use typedef to create aliases for the structure and union
typedef struct SNN SNN;
typedef union Data Data;
// Function to modify a neuron name of SNN by reference
void modifyName(SNN *snn, char *newName) {
  snn->neuronName = newName;
}
void modifyNumber(SNN *snn, int newNumber) {
  snn->neuronNumber = newNumber;
}
// Function to modify the common data of a SNN by reference
void modifyData(SNN *snn, Data *data) {
  snn->commonData.intData = data->intData;
  snn->commonData.doubleData = data->doubleData;
  snn->commonData.stringData = data->stringData;
}

int main() {
  printf("____________________Task1____________________\n");
  // Initialize a byte with binary value 11101100 (in hexadecimal, 0xec)
  int data = 0b11101100;
  // Display the initial value of 'data' in binary
  printf("Initial data: 0x%02X\n", data);
  printf("In binary: ");
  for(int i =sizeof(data)*2-1;i>=0;i--){                                //This will print data in binary
    if(data>>i & 1)
      printf("1");
    else
      printf("0");
  }printf("\n\n");
  // Set the 3rd bit (counting from 0): 11101100 no change since 3rd bit was already 1
  data = (1<<2|data);
  printf("After setting 3rd bit: 0x%02X\n", data);
  printf("In binary: ");
  for(int i =sizeof(data)*2-1;i>=0;i--){
    if(data>>i & 1)
      printf("1");
    else
      printf("0");
  }printf("\n\n");
  // Clear the 5th bit: 11001100
  data = (data&(~(1<<5)));
  printf("After clearing 5th bit: 0x%02X\n", data);
  printf("In binary: ");
  for(int i =sizeof(data)*2-1;i>=0;i--){
    if(data>>i & 1)
      printf("1");
    else
      printf("0");
  }printf("\n\n");
  // Toggle the 7th bit: 01001100
  data = (data^(1<<7));
  printf("After toggling 7th bit: 0x%02X\n", data);
  printf("In binary: ");
  for(int i =sizeof(data)*2-1;i>=0;i--){
    if(data>>i & 1)
      printf("1");
    else
      printf("0");
  }printf("\n\n");
  // Check and print a message if the 7th bit is set
  char seventh = data>>7;
  if(~seventh)
    printf("7th bit is 0\nSuccessfully toggled!\n");
  else
    printf("7th bit is 1\n");

  printf("____________________Task2____________________\n");

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
  matOut= malloc(sizeof(int*)*ROWS_A);                            //Initialize matOut with appropriate size        
  for(int i =0 ;i <ROWS_A;i++)                                    //so that it can be used with array accessing  
    matOut[i]=malloc(sizeof(int)*COLS_B);
  // Multiply matrices matA and matB
  matrix_multiply(&matA[0][0],&matB[0][0],matOut);                //Pass the most easily accessble parameters by definition
  // Print the result of the matrix multiplication
  for(int i = 0; i<ROWS_A;i++){
    for(int j = 0; j<COLS_B;j++)
      printf("%d ",matOut[i][j]);
    printf("\n");
  }


  for(int i = 0;i<ROWS_A;i++){                                    //Free inner memory first, then the pointer
    free(matOut[i]);
  }                                                               //It was okay to set matOut=NULL
  free(matOut);                                                   //It is effective to prevent many errors

  printf("____________________Task3____________________\n");

  FILE *inFile;
  FILE *outFile;
  int **matA1;                                                     //Names are different from Task3.s
  int **matB1;
  int **matOut1;
  // Allocate memory for matA, matB, and matOut
  matOut1 = (int**)malloc(sizeof(int*)*ROWS_A1);                   //Allocate appropriate memory using malloc and loop
  for(int i =0 ;i <ROWS_A1;i++)
    matOut1[i]=(int*)malloc(sizeof(int)*COLS_B1);
  
  matA1 = (int**)malloc(sizeof(int*)*ROWS_A1);
  for(int i =0 ;i <ROWS_A1;i++)
    matA1[i]=(int*)malloc(sizeof(int)*COLS_A1);

  matB1 = (int**)malloc(sizeof(int*)*ROWS_B1);
  for(int i =0 ;i <ROWS_B1;i++)
    matB1[i]=(int*)malloc(sizeof(int)*COLS_B1);

  // Open the file for reading and load integers to matA and matB
  inFile = fopen("matrices.txt","r");                               //Open and read data into matrices
  for(int i = 0; i<ROWS_A1;i++){
    for(int j = 0; j<COLS_A1;j++){
      fscanf(inFile, "%d ",&matA1[i][j]);                           //This is possible thanks to malloc
    }
  }

  for(int i = 0; i<ROWS_B1;i++){
    for(int j = 0; j<COLS_B1;j++){
      fscanf(inFile, "%d ",&matB1[i][j]);
    }
  }

  // Multiply matrices matA and matB
  matrix_multiply1(matA1,matB1,matOut1);                            //Pass parameters
  // Write the result of the matrix multiplication
  outFile = fopen("./output.txt", "w+");
  for(int i = 0; i<ROWS_A1;i++){
    for(int j = 0; j<COLS_B1;j++){
      fprintf(outFile,"%d ", matOut1[i][j]);                        //Also possible thanks to malloc
    }
    fprintf(outFile,"\n");
  }

  // Free the dynamically allocated memories
  
  for(int i =0 ;i <ROWS_A1;i++){                                    //Free inner memory first
    free(matOut1[i]);
    free(matA1[i]);
  }
  free(matOut1);
  free(matA1);                                                      //Free outer pointer

  for(int i =0 ;i <ROWS_B1;i++){
    free(matB1[i]);
  }
  free(matB1);

  //Close the file
  fclose(inFile);
  fclose(outFile);
  printf("\t<output.txt generated>\n");


  printf("____________________Task4____________________\n");
    // Create an instance of the SNN structure
  SNN snnA;
  snnA.neuronName = (char*)malloc(sizeof(char)*10);
  strcpy(snnA.neuronName, "LIF Neuron");
  snnA.neuronNumber = 100;

  // Create an instance of the Data union
  Data dataA;
  dataA.intData = 150;
  printf("dataA: %d\n", dataA.intData);                             //Print int data before getting overriden
  dataA.doubleData = 12.7;
  printf("dataA: %f\n", dataA.doubleData);                          //Print double data before getting overriden
  dataA.stringData = "Number of synapses and average weight";
  printf("dataA: %s\n", dataA.stringData);
  // Call the modifyName function by reference to change the name of snnA
  modifyName(&snnA, "Hodgkin-Huxley");
  // Call the modifyAge function by reference to change the number of snnA
  modifyNumber(&snnA, 20);
  // Call the modifyData function by reference to change the common data of snnA
  modifyData(&snnA, &dataA);
  // Display the modified snnA information
  printf("SNN name: %s\n",snnA.neuronName);
  printf("SNN number: %d\n",snnA.neuronNumber);
  printf("SNN common data: %s\n",snnA.commonData.stringData);       //Check what values are accessed through Union type
  printf("dataA(int & double attributes) after stringData initialization: \nint: %d, double: %f\n",snnA.commonData.intData,snnA.commonData.doubleData);
  return 0;
}