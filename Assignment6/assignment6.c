/*
* File: assignment6.c
* Owner: Hojun Kwak
* Date: 04.24.2024
* Description: Implement a word detection program using pthread functions in C
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void* word_detect_join(void *vargp);
void* word_detect_detach(void *vargp);
clock_t join_start_time;
clock_t join_end_time;
clock_t detach_start_time;
clock_t detach_end_time;
char* word;                     //Extra global variables to store values
char* word_join;                //returned from each thread
char* word_detach;
int count_join;
int count_detach;
void *ret;


int main() {
    pthread_t tid = pthread_self();
    printf("main: %u\n", (unsigned int)tid);

    while(1) {
        char str[100];
        char sentence_join[100];
        char sentence_detach[100];
        pthread_t tid;
        printf("Word to count: ");
        scanf("%99s", str);
        if(strcmp(str, "quit") == 0)
            break;
        word = malloc(sizeof(char*));
        strcpy(word,str);
        getchar();
        printf("String to count word from: ");
        fgets(sentence_join, sizeof(sentence_join), stdin);
        strcpy(sentence_detach,sentence_join);
	// TODO: Create a peer thread for word_detect_join, detecting a word in the str buffer using pthread_join
        pthread_t tid_join;                         //Created them for each thread to avoid any unexpected behavior
        pthread_t tid_detach;
        pthread_create(&tid_join, NULL, word_detect_join, sentence_join);
        pthread_create(&tid_detach, NULL, word_detect_detach, strdup(sentence_detach));
        join_start_time=clock();                //To count the time from detect_join
        pthread_join(tid_join, &ret);
        join_end_time=clock();
        printf("JOIN: \"%s\": %d\n",word_join,count_join);
        printf("JOIN TIME: %f\n",(double)(join_end_time-join_start_time)/CLOCKS_PER_SEC);
	// TODO: Create a peer thread for word_detect_detach, detecting a word in the str buffer using pthread_detach
        // pthread_t detatch;
        detach_start_time=clock();              //To count the time from detect_detach
        pthread_detach(tid_detach);
        detach_end_time=clock();
        printf("DETACH: \"%s\": %d\n",word_detach,count_detach);
        printf("DETACH TIME: %f\n",(double)(detach_end_time-detach_start_time)/CLOCKS_PER_SEC);
        // pthread_detach(tid);
    }
    // TODO: Free the str buffer if you dynamically allocate the string memory
    free(word_join);
    free(word_detach);
    return 0;
}

void* word_detect_join(void *vargp) {
    // TODO: Implement a peer thread using pthread_join to detect a word in the argument passed
    count_join = 0;
    char *token1 = strtok((char*)vargp, " ,.!?\t\n");
    // TODO: Print the detected word and frequency if there are multiple detections
    word_join = malloc(sizeof(char*));
    strcpy(word_join,word);
    while (token1 != NULL) {
        if (strcmp(token1, word_join) == 0)
            count_join++;                           //increment counter
        token1 = strtok(NULL, " ,.!?\t\n");
    }
    // TODO: Calculate the elapsed execution time in the thread execution using join_start_time and join_end_time 
    // i.e., join_start_time = clock(); <... your thread function>; join_end_time = clock(); join_execution_time = join_end_time - join_start_time;
    return NULL;
}
void* word_detect_detach(void *vargp) {
    word_detach = malloc(sizeof(char*));
    strcpy(word_detach,word);
    // TODO: Implement a peer thread using pthread_detach to detect a word in the argument passed
    count_detach = 0;
    char *token = strtok((char*)vargp, " ,.!?\t\n");
    // TODO: Print the detected word and frequency if there are multiple detections
    while (token != NULL) {
        if (strcmp(token, word_detach) == 0)
            count_detach++;                         //increment counter
        token = strtok(NULL, " ,.!?\t\n");
    }
    // TODO: Calculate the elapsed execution time in the thread execution using detach_start_time and detach_end_time 
    return NULL;
}

