#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
  // Create an instance of the SNN structure
  SNN snnA;
  snnA.neuronName = (char*)malloc(sizeof(char)*10);
  strcpy(snnA.neuronName, "LIF Neuron");
  snnA.neuronNumber = 100;

  // Create an instance of the Data union
  Data dataA;
  dataA.intData = 150;
  printf("dataA: %d\n", dataA.intData);
  dataA.doubleData = 12.7;
  printf("dataA: %f\n", dataA.doubleData);
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
  printf("SNN common data: %s\n",snnA.commonData.stringData);
  printf("dataA(int & double attributes) after stringData initialization: \nint: %d\n",snnA.commonData.intData);
  printf("double: %f\n",snnA.commonData.doubleData);
  return 0;
}