//#include <stdio.h>
//#include <pthread.h>
//#include <semaphore.h>
//
//#define TOTAL_READERS 10
//#define TOTAL_WRITERS 5
//
//sem_t wrt;  // binary semaphore used for both for mutual exclusion and signalling
//pthread_mutex_t mutex;  // Provides mutual exclusion when read_count is being modified
//int reader_count = 0; // To keep count of the total readers
//int count = 1;
//
//void *writer(void *wno) {
//    sem_wait(&wrt);
//    count = count * 2;
//    printf("Writer %d modified count to %d\n", *(int *) wno, count);
//    sem_post(&wrt);
//}
//
//void *reader(void *rno) {
//    // reader acquires lock before modifying read_count
//    pthread_mutex_lock(&mutex);
//    reader_count++;
//    if (reader_count == 1) {
//        sem_wait(&wrt); // if this is the first reader then it will block the writer
//    }
//    pthread_mutex_unlock(&mutex);
//    // reading section
//    printf("Reader %d modified count to %d\n", *(int *) rno, count);
//    // reader acquires the lock before modifying reader_count
//    pthread_mutex_lock(&mutex);
//    reader_count--;
//    if (reader_count == 0) {
//        sem_post(&wrt);     // If this is the last reader, it will wake up the writer.
//    }
//    pthread_mutex_unlock(&mutex);
//}
//
//int main() {
//    pthread_t read[TOTAL_READERS], write[TOTAL_WRITERS]; // creating reader and writer threads
//    pthread_mutex_init(&mutex, NULL);
//    sem_init(&wrt, 0, 1);
//
//    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // used for numbering the producer and consumer
//
//    // main() function can exit before producer and consumer threads are executed
//    // this can be prevented by using join operation
//    // pthread_join() function provides a simple mechanism allowing an application to wait for a thread to terminate.
//    for (int i = 0; i < 10; i++) {
//        pthread_create(&read[i], NULL, (void *) reader, (void *) &a[i]);
//    }
//    for (int i = 0; i < 5; i++) {
//        pthread_create(&write[i], NULL, (void *) writer, (void *) &a[i]);
//    }
//
//    for (int i = 0; i < 10; i++) {
//        pthread_join(read[i], NULL);
//    }
//    for (int i = 0; i < 5; i++) {
//        pthread_join(write[i], NULL);
//    }
//
//    pthread_mutex_destroy(&mutex);  // destroy the mutex to avoid memory leak
//    sem_destroy(&wrt);
//
//    return 0;
//}
//
///*
//OUTPUT:
//Reader 1 modified count to 1
//Reader 2 modified count to 1
//Reader 3 modified count to 1
//Reader 4 modified count to 1
//Reader 5 modified count to 1
//Reader 6 modified count to 1
//Reader 7 modified count to 1
//Reader 8 modified count to 1
//Reader 9 modified count to 1
//Reader 10 modified count to 1
//Writer 1 modified count to 2
//Writer 2 modified count to 4
//Writer 3 modified count to 8
//Writer 4 modified count to 16
//Writer 5 modified count to 32
//*/