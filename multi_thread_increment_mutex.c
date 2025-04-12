#include <stdio.h>
#include <pthread.h>
#include "function.h"

#define MAX_THREAD 10

extern int number;

extern pthread_mutex_t lock;

int main(){
    pthread_t threads[MAX_THREAD];

    pthread_mutex_init(&lock, NULL);

    printf("Numero prima dell' incremento: %d\n", number);

    for(int i = 0; i < MAX_THREAD; i++){
        pthread_create(&threads[i], NULL, thread_increment_mutex, &number);
    }

    for(int i = 0; i < MAX_THREAD; i++){
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("Numero dopo incremento: %d\n", number);
    
    return 0;
}