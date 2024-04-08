#include <stdio.h>
#include "macros.h"

int add(int a, int b){
	return a+b;
}
int sub(int a, int b){
	return a-b;
}
int mul(int a, int b){
	return a*b;
}

void calculator(int a, int b, int option){
	switch(option){
		case 1:printf("%d+%d=%d\n",a,b,add(a,b));break;
		case 2:printf("%d-%d=%d\n",a,b,sub(a,b));break;
		case 3:printf("%d*%d=%d\n",a,b,mul(a,b));break;
		case 4:printf("%d^2=%d\n",a, SQUARE(a));break;
		case 5:printf("%d^3=%d\n",a,CUBE(a));break;
		case 6:printf("%d*2=%d\n",a,DOUBLE(a));break;
		case 7:printf("%d*3=%d\n",a,TRIPLE(a));break;
	}
}

int main(void){
	int option, a, b;
	void(*cal)(int, int, int) = &calculator;
	printf("Choose Option: \n|(1) addition\n|(2) subtraction\n|(3) multiplication\n|(4) square\n|(5) cube\n|(6) double\n|(7) triple\n");
	scanf("%d",&option);
	if(option<4){
		printf("Enter two integers(separated by space): ");
		scanf("%d %d",&a, &b);
		cal(a,b,option);
	}
	else{
		printf("Enter an integer: ");
		scanf("%d",&a);
		cal(a,0,option);
	}
}
