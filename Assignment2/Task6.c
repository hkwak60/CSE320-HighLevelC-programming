#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
                wordCount++;
                token=strtok(NULL," .!,");
        }
        printf("Numer of words: %d\n",wordCount);

        Words words[wordCount];
        for(int i = 0; i<wordCount;i++)
                words[i].occur=0;
        token = strtok(sentence2," .!,");
        words[0].word = token;
        words[0].occur++;
        int diff = 1;
        bool alreadyIn;
        while(token!=NULL){
                token = strtok(NULL," .!,");
                if(token!=NULL){
                        alreadyIn=false;
                        for(int i = 0; i<diff;i++){
                                if(strcmp(words[i].word,token)==0){
                                        words[i].occur++;
                                        alreadyIn = true;
                                }
                        }
                        if(!alreadyIn){
                                words[diff].word = token;
                                words[diff++].occur++;
                        }
                }
        }
        int mostOccured = 0;
        for(int i = 0; i<diff;i++){
                if(mostOccured<words[i].occur)
                        mostOccured=words[i].occur;
        }
        printf("The most Ocured word is/words are: ");
        for(int i = 0; i<diff;i++){
                if(words[i].occur==mostOccured)
                        printf("\n%s ", words[i].word);
        }
        printf("of %d occurences.\n",mostOccured);

}