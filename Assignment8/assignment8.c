/*
* File: assignment8.c
* Owner: Hojun Kwak
* Date: 05.14.2024
* Description: Implement of sleeping barber problem in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_CHAIRS 5
#define TOTAL_CUST 10

sem_t barber_sem, customer_sem, access_seats_sem, haircut_sem, barber_done_sem;
pthread_mutex_t serve_mut;
int num_waiting = 0; int wid=0,did=1;   //For clean output
void* barber(void* arg) {
    while (1) {
        sem_wait(&customer_sem);    //Deleted sem_wait(access_seats_sem)
        if (num_waiting > 0) {
            num_waiting--;
            printf("Barber: Cutting hair. Customers waiting: %d\n", num_waiting);
            sem_post(&access_seats_sem);
            // Simulate haircut
            sleep(2);
            sem_post(&haircut_sem);
            sem_post(&barber_done_sem);
            did++;
        } else {
            // If no customers are waiting, release the access_seats_sem
            sem_post(&access_seats_sem);
        }
        if(did==TOTAL_CUST)
            break;
    }
    pthread_exit(NULL);
}
void* customer(void* arg) {
    sem_wait(&access_seats_sem);
    if (num_waiting < NUM_CHAIRS) {
        num_waiting++;
        printf("Customer %d: Arrived. Customers waiting: %d\n",++wid, num_waiting);
        sem_post(&access_seats_sem);
        sem_post(&customer_sem);
        sem_wait(&haircut_sem);
        printf("Customer %d: Got a haircut.\n",did);
        // Acknowledge that the haircut is done
        sem_wait(&barber_done_sem);
    } else {
        printf("Customer %d: No seats available. Leaving.\n",++wid);
        sem_post(&access_seats_sem);
    }
    if(did==TOTAL_CUST)
        exit(0);
    pthread_exit(NULL);
}
int main() {
    pthread_t barber_thread, customer_threads[20];
    pthread_mutex_init(&serve_mut,NULL);
    sem_init(&barber_sem, 0, 0);
    sem_init(&customer_sem, 0, 0);
    sem_init(&access_seats_sem, 0, 1);
    sem_init(&haircut_sem, 0, 0);
    sem_init(&barber_done_sem, 0, 0);
    pthread_create(&barber_thread, NULL, barber, NULL);
    for (int i = 0; i < 10; ++i) {
        pthread_create(&customer_threads[i], NULL, customer, NULL);
        // Sleep to simulate time between customer arrivals
        sleep(1);
    }
    pthread_join(barber_thread, NULL);
    for (int i = 0; i < 10; ++i) {
        pthread_join(customer_threads[i], NULL);
    }
    printf("done\n");
    sem_destroy(&barber_sem);
    sem_destroy(&customer_sem);
    sem_destroy(&access_seats_sem);
    sem_destroy(&haircut_sem);
    sem_destroy(&barber_done_sem);
    return 0;
}

