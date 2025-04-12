#include "function.h"

int number = 0;

pthread_mutex_t lock;

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