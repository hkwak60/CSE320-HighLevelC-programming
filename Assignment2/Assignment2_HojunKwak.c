#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "macros.h"
#include <stdbool.h>
#include <ctype.h>


//Task 1 . 1 Define and demostrate the use of custom data types using typedef
typedef struct dateOfBirth{
        int year;
        int month;
        int day;
}DATE;
// With this, I can now use the dateOfBirth struct type with just DATE keyword

//Task 1 . 2 use enum to define months
//January is given the initial value of 1 since it is the first month ofthe year
typedef enum Months {
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
}MONTHS;

//Task 1 . 3 write a function that uses enum and prints out information
void birthday(MONTHS mm, int yy, int dd){
	printf("I was born in %d.%d.%d\n",yy,mm,dd);	
}


//Task 2 . 2 Implement a function that finds the sum and average of an integer array
int sum(int* ptr, int size){
	int res = 0;
	for(int i = 0; i<size;i++)
		res+=*(ptr+i);
	return res;
}

double average(int sum, int size){
	return (double)sum/size;
}

//Task 3 . 1 Define a C structure to represent a wash machine with attributes like name, type, date manufactured, and manufacturer.
typedef struct{
	char name[20];
	char type[20];
	int dateManufactured;
	char manufacturer[20];
}WashingMachine;

//Task 4 . 1 Create a program that calculates the factorial of a given integer using a recursive function.
int fac(int n){
	if(n==1)
		return n;
	else
		return n*fac(n-1);
}

//Task 4 . 2 Implement a function pointer to handle mathematical operations (addition, subtraction, multiplication).
void add(int a, int b){
	printf("%d + %d = %d\n", a,b,a+b);
}
void sub(int a, int b){
	printf("%d - %d = %d\n", a,b,a-b);
}
void mul(int a, int b){
	printf("%d * %d = %d\n", a,b,a*b);
}

//Task 5 . 3 Modify your calculator program to utilize the macros for arithmetic operations.
void utilize_macros(int a, int option){
        switch(option){
                case 4:printf("%d ^ 2 = %d\n",a,SQUARE(a));break;
                case 5:printf("%d ^ 3 = %d\n",a,CUBE(a));break;
                case 6:printf("%d * 2 = %d\n",a,DOUBLE(a));break;
                case 7:printf("%d * 3 = %d\n",a,TRIPLE(a));break;
        }
}

//Task 6 . 2 Create a program that reads a text file, counts the number of words, and displays the most common word.
typedef struct WordOccurence{
        char* word;
        int occur;
}Words;

int main(void){

        printf("\t____________________TASK1____________________\n");
        DATE myBirthday;                                                //Declare DATE type
        myBirthday.day = 12;                                            //and initialize it's value
        myBirthday.month = September;
        myBirthday.year = 2001;
        birthday(myBirthday.month,myBirthday.year,myBirthday.day);      //Print out necessary info


        printf("\t____________________TASK2____________________\n");
        int *ptr, size, sumOfNumbers;
        double averageOfNumbers;
        printf("Enter total number of data: ");                         //Get size of array
        scanf("%d",&size);
        int arr[size];                                                  //Allocate memory prior to initialization
        ptr = arr;                                                      //Make the pointer point to the array
	printf("Enter %d numbers:\n",size);
	for(int i = 0; i<size;i++)
                scanf("%d",ptr+i);                                      //Get numbers and initlize the array

	sumOfNumbers=sum(ptr,size);
	printf("Sum: %d\n",sumOfNumbers);
	printf("Average: %.2f\n",average(sumOfNumbers,size));           //Print out calculated results


        printf("\t____________________TASK3____________________\n");    
        int total;
	printf("Enter number of washing machines: ");
	scanf("%d",&total);                                             //Get total number of Washing Machines
	WashingMachine Machines[total];
	for(int i = 0 ; i<total;i++){
		printf("Machine %d:\nEnter name: ",i+1);
		scanf("%s",Machines[i].name);
		printf("Enter type: ");
		scanf("%s",Machines[i].type);
		printf("Enter manufactured date(YYYYMMDD): ");
		scanf("%d",&Machines[i].dateManufactured);
		printf("Enter manufacturer: ");
		scanf("%s",Machines[i].manufacturer);                   //Initialize Washing Machine fields
	}
	FILE *fptr=fopen("data.bin","wb");                              //fopen("__","wb") will initialize file pointer to
                                                                        //create and write in a binary file
	if(fptr==NULL){
		printf("Error, no file to write");                      //IO exeption handling
		exit(1);
	}
	fwrite(Machines, sizeof(WashingMachine), total, fptr);          //fwrite(pointer, size, count, file_stream)
	fclose(fptr);


	WashingMachine ReadMac[total];                                  //Create another Washingmachine array to read from the created .bin file
	fptr=fopen("data.bin","rb");
	if(fptr==NULL){
		printf("Error, no file to write");                      //IO exeption handling
		exit(1);
	}
	fread(ReadMac, sizeof(WashingMachine),total, fptr);             //fwrite(pointer, size, count, file_stream)
	fclose(fptr);
	for(int i = 0; i<total;i++){
		printf("Machine %d: %s| %s| %d| %s\n", (i+1), ReadMac[i].name, ReadMac[i].type, ReadMac[i].dateManufactured, ReadMac[i].manufacturer);
	}
    


        printf("\t____________________TASK4____________________\n");
        int n, option=100, a, b;                                        //Give the option an impossible intial value
        void (*cal[])(int, int)={add,sub,mul,NULL};                     //Array of function pointers for effective use,
                                                                        //the NULL at the end is for making TASK5 easier
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("Factorial: %d\n",fac(n));                               //Output of factorial using recursion
        while(!(option<4&&option>0)){                                   //Segmentation Fault handling
                printf("Choose Option: \n|(1) addition \n|(2) subtraction \n|(3) multiplication\n");
                scanf("%d",&option);
        }
	printf("Enter two integers(separated by space): ");
	scanf("%d %d",&a, &b);
        cal[option-1](a,b);                                             //Initilization of functions through function pointers
    
    
        printf("\t____________________TASK5____________________\n");
        option=100;                                                     //Reset option
        cal[3]=&utilize_macros;                                         //Task 5 . 3
        while(!(option<8&&option>0)){
                printf("Choose Option: \n|(1) addition\n|(2) subtraction\n|(3) multiplication\n|(4) square\n|(5) cube\n|(6) double\n|(7) triple\n");
                scanf("%d",&option);
        }
        if(option<4){
                printf("Enter two integers(separated by space): ");
                scanf("%d %d",&a, &b);
                cal[option-1](a,b);
        }
        else{                                                           //cal function takes a and option as parameter and treats them accordingly
                printf("Enter one integer: ");
                scanf("%d",&a);
                cal[3](a,option);
        }
        
        
        printf("\t____________________TASK6____________________\n");
        fptr = fopen("text.txt", "r");
        if(fptr==NULL){                                                 
                printf("Error! No file to read");                       //IO Exception handling
                exit(1);
        }
        char *sentence = malloc(400);                                   //Big enough size to store read data     
        fgets(sentence, 400, fptr);                                     //Read text separated with '\n'
        fclose(fptr);
        printf("%s\n",sentence);                                        //Show the user the original text
        for(int i = 0; i<400;i++)
                sentence[i] = tolower(sentence[i]);                     //Make all characters lower case by utilizing <ctype.h>
        char *sentence2 = malloc(500);                                  //String to copy to has to be greater than string to copy from
        strcpy(sentence2, sentence);                                    //Copy string since strtok() will ruin the original text

        int wordCount=0;
        char* token = strtok(sentence," .!,");                          //Use strtok(str, delim) to count words
        while(token!=NULL){
                wordCount++;
                token=strtok(NULL," .!,");
        }
        printf("Numer of words: %d\n",wordCount);

        Words words[wordCount];                                         //This struct array will store how much each word has occured, 
                                                                        //somewhat similar to dictionary type in python
        for(int i = 0; i<wordCount;i++)
                words[i].occur=0;                                       //Initialize original occurence to 0
        token = strtok(sentence2," .!,");
        words[0].word = token;
        words[0].occur++;                                               //Store first word to database and increment occurence
        int diff = 1;                                                   //Indicates how many different words are in the text
        bool alreadyIn;                                                 //<stdbool.h> feature to indicate whether word was already stored
        while(token!=NULL){
                token = strtok(NULL," .!,");
                if(token!=NULL){
                        alreadyIn=false;                                //Reset boolean to assume the word is new
                        for(int i = 0; i<diff;i++){
                                if(strcmp(words[i].word,token)==0){
                                        words[i].occur++;               //Since the word exsists in the database, increment
                                        alreadyIn = true;               //and change the bool to true
                                }
                        }
                        if(!alreadyIn){
                                words[diff].word = token;               //Since the word doesen't exist in the database, add the word
                                words[diff++].occur++;                  //and make the occurence to 1
                        }
                }
        }
        int mostOccured = 0;                                            //int value to determine the most occured word
        for(int i = 0; i<diff;i++){
                if(mostOccured<words[i].occur)
                        mostOccured=words[i].occur;                     //Since there is a more occured word, change the most occurence number
        }
        printf("The most Ocured word is/words are: ");
        for(int i = 0; i<diff;i++){
                if(words[i].occur==mostOccured)                         //Print all words(if more than one) most occured in text
                        printf("\n%s ", words[i].word);
        }
        printf("of %d occurences.\n",mostOccured);
}	
	
