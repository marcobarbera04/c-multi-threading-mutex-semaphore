#include <stdio.h>
#include <pthread.h>
#include "function.h"

#define MAX_THREAD 10

extern int number;

extern pthread_mutex_t lock;

int main(){
    pthread_t threads[MAX_THREAD];
    int threads_ids[MAX_THREAD];

    pthread_mutex_init(&lock, NULL);

    printf("Number before increment: %d\n", number);

    for(int i = 0; i < MAX_THREAD; i++){
        threads_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_increment_mutex, &threads_ids[i]);
    }

    for(int i = 0; i < MAX_THREAD; i++){
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("Number after increment: %d\n", number);
    
    return 0;
}