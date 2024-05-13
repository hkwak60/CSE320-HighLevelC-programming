/*
* File: assignment7_2.c
* Owner: Hojun Kwak
* Date: 05.01.2024
* Description: Implement the first readers-writers problem using semaphores in C
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

typedef struct {
    sem_t mutex;
    sem_t rlock;
    int writecount;
} rwlock;

typedef struct {
    int data;
    int copy;
    rwlock lock;
} object;

void rwlock_init(rwlock *lock) {
    sem_init(&lock->mutex, 0, 1);
    sem_init(&lock->rlock, 0, 1);
    lock->writecount = 0;
}

void rwlock_deinit(rwlock *lock) {
    sem_destroy(&lock->mutex);
    sem_destroy(&lock->rlock);
}

void acquire_reader_lock(rwlock *lock) {
    sem_wait(&lock->rlock);
}

void release_reader_lock(rwlock *lock) {
    sem_post(&lock->rlock);
}

void acquire_writer_lock(rwlock *lock) {
    sem_wait(&lock->mutex);
    lock->writecount++;
    if(lock->writecount == 1) //if this is the first writer
        sem_wait(&lock->rlock);//wait for a reader to finish or block readers
    sem_post(&lock->mutex);
}

void release_writer_lock(rwlock *lock) {
    sem_wait(&lock->mutex);
    lock->writecount--;
    if(lock->writecount == 0)   //if this is the last writer
        sem_post(&lock->rlock); //unblock any waiting readers
    sem_post(&lock->mutex);
}

void* reader(void *vargp) {
    object* pobj = (object*)vargp;
    int i;
    for(i = 0; i < 100; i++) {
        acquire_reader_lock(&pobj->lock);
        int data = pobj->data;
        int copy = pobj->copy;
        release_reader_lock(&pobj->lock);
        printf("R_%d: data: %d, copy: %d\n", i, data, copy);
    }
}

void* writer(void *vargp) {
    object* pobj = (object*)vargp;
    int i;
    for(i = 0; i < 100; i++) {
        acquire_writer_lock(&pobj->lock);
        int data = pobj->data = i % 10;
        int copy = pobj->copy = pobj->data;
        release_writer_lock(&pobj->lock);
        printf("W_%d: data: %d, copy: %d\n", i, data, copy);
    }
}

int main() {
    pthread_t tid[3];
    object obj;
    obj.data = obj.copy = 0;
    rwlock_init(&obj.lock);

    pthread_create(tid+0, 0, reader, &obj);
    pthread_create(tid+1, 0, reader, &obj);
    pthread_create(tid+2, 0, writer, &obj);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);

    rwlock_deinit(&obj.lock);
}
