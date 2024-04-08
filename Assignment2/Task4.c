#include <stdio.h>

int fac(int n){
	if(n==1)
		return n;
	else
		return n*fac(n-1);
}

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
	}
}

int main(void){
	int n, option, a, b;
	void(*cal)(int, int, int) = &calculator;
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("Factorial: %d\n",fac(n));
	printf("Choose Option: (1) addition |(2) subtraction |(3) multiplication\n");
	scanf("%d",&option);
	printf("Enter two integers(separated by space): ");
	scanf("%d %d",&a, &b);
	cal(a,b,option);

}
