#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct WordOccurence{
        char* word;
        int occur;
}Words;

int main(void){
        
        FILE *fptr = fopen("text.txt", "r");
        if(fptr==NULL){
                printf("Error! No file to read");
                exit(1);
        }
        char *sentence = malloc(400);
        fgets(sentence, 400, fptr);
        fclose(fptr);
        char *sentence2 = malloc(500);
        strcpy(sentence2, sentence);
        printf("%s\n",sentence2);

        int wordCount=0;
        char* token = strtok(sentence," .!,");
        while(token!=NULL){
                printf("%s\n",token);
                wordCount++;
                token=strtok(NULL," .!,");
        }
        printf("Numer of words: %d\n",wordCount);
}