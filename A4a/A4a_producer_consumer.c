// Assignment 4A - Producer Consumer Problem
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_ITEMS 5
#define BUFFER_SIZE 5

sem_t empty;    // Number of empty slots in buffer
sem_t full;     // Number of slots filled
pthread_mutex_t mutex;  // Used to provide mutual exclusion for critical section

int in = 0;  // index at which producer will put the next data
int out = 0; // index from which the consumer will consume next data

int buffer[BUFFER_SIZE];

void producer(void *pno) {
    int item;
    for (int i = 0; i < MAX_ITEMS; i++) {
        item = rand();  // produce a random item
        // WAIT OPERATIONS
        sem_wait(&empty);   // wait/sleep when there are no empty slots for insertion
        pthread_mutex_lock(&mutex); // acquire the lock, same as wait operation

        // PRODUCING DATA...
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *) pno), buffer[in], in);
        in = (in + 1) % BUFFER_SIZE;

        // SIGNAL OPERATIONS
        pthread_mutex_unlock(&mutex);   // release the lock
        sem_post(&full);    // Signal/wake to consumer that buffer has some data and they can consume now
    }
}

void *consumer(void *cno) {
    int item;
    for (int i = 0; i < MAX_ITEMS; i++) {
        // WAIT OPERATIONS
        sem_wait(&full);    // wait/sleep when there are no full slots, i.e all slots are empty nothing to consume
        pthread_mutex_lock(&mutex); // acquire the lock, same as wait operation

        // CONSUMING DATA...
        item = buffer[out];     // consume an item
        printf("Consumer %d: Remove Item %d from %d\n", *((int *) cno), item, out);
        out = (out + 1) % BUFFER_SIZE;

        // SIGNAL OPERATIONS
        pthread_mutex_unlock(&mutex);   // release the lock
        sem_post(&empty);    // Signal/wake the producer that buffer slots are empty and they can produce more items
    }
}

int main() {
    pthread_t pro[MAX_ITEMS], con[MAX_ITEMS];
    pthread_mutex_init(&mutex, NULL);   // Initialise the mutex

    // pshared = 0 means multiple threads can be shared
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    int a[MAX_ITEMS] = {1, 2, 3, 4, 5}; // Just used for numbering producer and consumer threads

    // creating 5 producer threads
    for (int i = 0; i < MAX_ITEMS; i++) {
        pthread_create(&pro[i], NULL, (void *) producer, (void *) &a[i]);
    }
    // creating 5 consumer threads
    for (int i = 0; i < MAX_ITEMS; i++) {
        pthread_create(&con[i], NULL, (void *) consumer, (void *) &a[i]);
    }
    // main() function can exit before producer and consumer threads are executed
    // this can be prevented by using join operation
    // pthread_join() function provides a simple mechanism allowing an application to wait for a thread to terminate.
    for (int i = 0; i < MAX_ITEMS; i++) {
        pthread_join(pro[i], NULL);
    }
    for (int i = 0; i < MAX_ITEMS; i++) {
        pthread_join(con[i], NULL);
    }
    pthread_mutex_destroy(&mutex);  // destroy the mutex to avoid memory leak
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}

/*
OUTPUT:
Producer 1: Insert Item 41 at 0
Producer 1: Insert Item 18467 at 1
Producer 2: Insert Item 41 at 2
Producer 1: Insert Item 6334 at 3
Producer 3: Insert Item 41 at 4
Consumer 1: Remove Item 41 from 0
Consumer 2: Remove Item 18467 from 1
Producer 2: Insert Item 18467 at 0
Consumer 5: Remove Item 41 from 2
Consumer 2: Remove Item 6334 from 3
Producer 4: Insert Item 41 at 1
Consumer 4: Remove Item 41 from 4
Consumer 1: Remove Item 18467 from 0
Producer 5: Insert Item 41 at 2
Producer 1: Insert Item 26500 at 3
Consumer 3: Remove Item 41 from 1
Producer 3: Insert Item 18467 at 4
Producer 2: Insert Item 6334 at 0
Consumer 5: Remove Item 41 from 2
Consumer 2: Remove Item 26500 from 3
Producer 1: Insert Item 19169 at 1
Consumer 4: Remove Item 18467 from 4
Consumer 1: Remove Item 6334 from 0
Producer 5: Insert Item 18467 at 2
Producer 4: Insert Item 18467 at 3
Consumer 3: Remove Item 19169 from 1
Producer 3: Insert Item 6334 at 4
Producer 2: Insert Item 26500 at 0
Consumer 5: Remove Item 18467 from 2
Consumer 2: Remove Item 18467 from 3
Producer 5: Insert Item 6334 at 1
Consumer 4: Remove Item 6334 from 4
Consumer 1: Remove Item 26500 from 0
Producer 4: Insert Item 6334 at 2
Producer 3: Insert Item 26500 at 3
Consumer 2: Remove Item 6334 from 1
Producer 2: Insert Item 19169 at 4
Producer 5: Insert Item 26500 at 0
Consumer 5: Remove Item 6334 from 2
Consumer 3: Remove Item 26500 from 3
Producer 4: Insert Item 26500 at 1
Consumer 4: Remove Item 19169 from 4
Consumer 1: Remove Item 26500 from 0
Producer 3: Insert Item 19169 at 2
Consumer 3: Remove Item 26500 from 1
Consumer 5: Remove Item 19169 from 2
Producer 4: Insert Item 19169 at 3
Producer 5: Insert Item 19169 at 4
Consumer 4: Remove Item 19169 from 3
Consumer 3: Remove Item 19169 from 4
*/