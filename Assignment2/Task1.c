#include <stdio.h>
#include <string.h>


//Task 1 . 1 Define and demostrate the use of custom data types using typedef
typedef struct _Worker{
	char name[20];
	int salary;
	int workedYears;
}Worker;

typedef struct _Office{
	char address[50];
	int roomNumber;
}Office;
// With this, I can now use two custom data types Worker and Office 
// without having to write 'struct' each time. 

int main(void){
	Worker W1;
	strcpy(W1.name, "Hojun");
	W1.salary = 1000000;
	W1.workedYears=1;

	Office MeetingRoom;
	strcpy(MeetingRoom.address, "Seoul, Yangchun Gu, Mokdong-Ro 100");
	MeetingRoom.roomNumber = 320;

	printf("%s has worked %d year and now has too attend a meeting at %s, %d\n", W1.name,W1.workedYears, MeetingRoom.address, MeetingRoom.roomNumber);

	//The code above shows the usage of custom data types

	enum Months {
		January =1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};
	//January is given the initial value of 1 since it is the first month ofthe year
	printf("I was born in the %dth month of the year\n",September);	
	//my enum types work fine



}	
	
