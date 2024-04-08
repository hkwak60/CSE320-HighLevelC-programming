#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[20];
	char type[20];
	int dateManufactured;
	char manufacturer[20];
}WashingMachine;

int main(void){
    int total;
    printf("Enter number of washing machines: ");
	scanf("%d",&total);
    FILE *fptr;
    WashingMachine ReadMac[total];
	fptr=fopen("data.bin","rb");
	if(fptr==NULL){
		printf("Error, no file to read");
		exit(1);
	}
	fread(ReadMac, sizeof(WashingMachine),total, fptr);
	fclose(fptr);
	for(int i = 0; i<total;i++){
		printf("Machine %d: %s| %s| %d| %s\n", (i+1), ReadMac[i].name, ReadMac[i].type, ReadMac[i].dateManufactured, ReadMac[i].manufacturer);
	}

}