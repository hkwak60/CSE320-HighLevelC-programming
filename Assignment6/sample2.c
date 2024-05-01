/*
* File: assignment6.c
* Owner: Hojun Kwak
* Date: 04.22.2024
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
char* word;


int main() {
    pthread_t tid = pthread_self();
    printf("main: %u\n", (unsigned int)tid);

    while(1) {
        char str[100];
        char sentence[100];
        pthread_t tid;
        printf("Word to count: ");
        scanf("%99s", str);
        if(strcmp(str, "quit") == 0)
            break;
        word = malloc(sizeof(char*));
        strcpy(word,str);
        getchar();
        printf("String to count word from: ");
        fgets(sentence, sizeof(sentence), stdin);
	// TODO: Create a peer thread for word_detect_join, detecting a word in the str buffer using pthread_join
        pthread_create(&tid, NULL, word_detect_join, strdup(sentence));
        void *ret;
        pthread_join(tid, &ret);
	// TODO: Create a peer thread for word_detect_detach, detecting a word in the str buffer using pthread_detach
        // pthread_t detatch;
        detach_start_time=clock();
        pthread_create(&tid, NULL, word_detect_detach, strdup(sentence));
        detach_end_time=clock();
        printf("JOIN TIME: %f\n",(double)(join_end_time-join_start_time)/1000);
        printf("DETACH TIME: %f\n",(double)(detach_end_time-detach_start_time)/1000);
        // pthread_detach(tid);
    }
    // TODO: Free the str buffer if you dynamically allocate the string memory
    return 0;
}

void* word_detect_join(void *vargp) {
    join_start_time=clock();
    // TODO: Implement a peer thread using pthread_join to detect a word in the argument passed
    int count = 0;
    char *token = strtok((char*)vargp, " ,.!?\t\n");
    // TODO: Print the detected word and frequency if there are multiple detections
    while (token != NULL) {
        if (strcmp(token, word) == 0)
            count++;
        token = strtok(NULL, " ,.!?\t\n");
    }
    printf("JOIN: \"%s\" occurence: %d\n",word, count);
    // TODO: Calculate the elapsed execution time in the thread execution using join_start_time and join_end_time 
    // i.e., join_start_time = clock(); <... your thread function>; join_end_time = clock(); join_execution_time = join_end_time - join_start_time;
    join_end_time=clock();
    return NULL;
}

void* word_detect_detach(void *vargp) {
    pthread_t tid = pthread_self();
    pthread_detach(tid);
    // TODO: Implement a peer thread using pthread_detach to detect a word in the argument passed
    int count = 0;
    char *token = strtok((char*)vargp, " ,.!?\t\n");
    // TODO: Print the detected word and frequency if there are multiple detections
    while (token != NULL) {
        if (strcmp(token, word) == 0)
            count++;
        token = strtok(NULL, " ,.!?\t\n");
    }
    printf("DETACHED: \"%s\" occurence: %d\n",word, count);
    free(token);
    // TODO: Calculate the elapsed execution time in the thread execution using detach_start_time and detach_end_time 
    return NULL;
}

