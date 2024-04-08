#include <stdio.h>

int main() {
  // Initialize a byte with binary value 11101100 (in hexadecimal, 0xec)
  int data = 0b11101100;
  // Display the initial value of 'data' in binary
  printf("Initial data: 0x%02X\n", data);
  printf("In binary: ");
  for(int i =sizeof(data)*2-1;i>=0;i--){
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
  return 0;
}