#include <stdio.h>
#include <stdlib.h>

int sum(int* ptr, int size){
	int res = 0;
	for(int i = 0; i<size;i++)
		res+=*(ptr+i);
	return res;
}

double average(int sum, int size){
	return (double)sum/size;
}

int main(void){
	int *ptr, size,sumOfNumbers;
	double averageOfNumbers;
	printf("Enter total number of data: ");
	scanf("%d",&size);
	ptr = (int *)malloc(size*sizeof(int));
	printf("Enter %d numbers:\n",size);
	for(int i = 0; i<size;i++)
		scanf("%d",ptr+i);

	sumOfNumbers=sum(ptr,size);
	averageOfNumbers=average(sumOfNumbers,size);
	printf("Sum: %d\n",sumOfNumbers);
	printf("Average: %f\n",averageOfNumbers);

}
