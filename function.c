#include "function.h"

int number = 0;

int numbers[BUFFER_SIZE] = {0};

pthread_mutex_t lock;

sem_t sem;

void* thread_increment(void* arg){
    int *n = (int*)arg; 
    pthread_t thread = pthread_self();
    for(int i = 0; i < MAX_INCREMENTS; i++){
        (*n)++;
    }
    printf("Thread %lu terminato, valore di n: %d\n", thread, *n);
    pthread_exit(NULL);
}

void* thread_increment_mutex(void* arg){
    pthread_mutex_lock(&lock);
    int *n = (int*)arg; 
    pthread_t thread = pthread_self();
    for(int i = 0; i < MAX_INCREMENTS; i++){
        (*n)++;
    }
    printf("Thread %lu terminato, valore di n: %d\n", thread, *n);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

void* thread_buffer_reading_semaphore(void* arg){
    int thread = *(int*)arg;
    sem_wait(&sem);
    for(int i = 0; i < BUFFER_SIZE; i++){
        printf("thread %d: [%d]%d\n", thread, i, numbers[i]);
    }
    sleep(2);   // sleep to see that 2 threads access the critical section at the time
    sem_post(&sem);
    pthread_exit(NULL);
}