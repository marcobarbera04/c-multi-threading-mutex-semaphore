#include "function.h"

int number = 0;

int numbers[BUFFER_SIZE] = {0};

pthread_mutex_t lock;

sem_t sem;

void* thread_increment(void* arg){
    int thread = *(int*)arg; 
    for(int i = 0; i < MAX_INCREMENTS; i++){
        number++;
    }
    printf("Thread %d terminated, value of number: %d\n", thread, number);
    pthread_exit(NULL);
}

void* thread_increment_mutex(void* arg){
    pthread_mutex_lock(&lock);
    int thread = *(int*)arg; 
    for(int i = 0; i < MAX_INCREMENTS; i++){
        number++;
    }
    printf("Thread %d terminated, value of number: %d\n", thread, number);
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