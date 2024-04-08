#include <stdio.h>

typedef struct{
	char* name;
	char* type;
	int dateManufactured;
	char* manufacturer;
}WashingMachine;
int main(void){
        int total;
	printf("Enter number of washing machines: ");
	scanf("%d",&total);
	WashingMachine Machines[total];
	for(int i = 0 ; i<total;i++){
		printf("Machine %d:\nEnter name: ",i+1);
		Machines[i].name = (char*)malloc(sizeof(char*));
		scanf("%s",Machines[i].name);
		printf("Enter type: ");
		Machines[i].type = (char*)malloc(sizeof(char*));
		scanf("%s",Machines[i].type);
		printf("Enter manufactured date(YYYYMMDD): ");
		scanf("%d",&Machines[i].dateManufactured);
		printf("Enter manufacturer: ");
		Machines[i].manufacturer = (char*)malloc(sizeof(char*));
		scanf("%s",Machines[i].manufacturer);
	}
	FILE *fptr = fopen("data.bin","wb");
	if(fptr==NULL){
		printf("Error, no file to write");
		exit(1);
	}
	fwrite(Machines, sizeof(WashingMachine), total, fptr);
	fclose(fptr);


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