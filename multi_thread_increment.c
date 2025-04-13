#include <stdio.h>
#include <pthread.h>
#include "function.h"

#define MAX_THREAD 10

extern int number;

int main(){
    pthread_t threads[MAX_THREAD];
    int threads_ids[MAX_THREAD];

    printf("Number before increment: %d\n", number);

    for(int i = 0; i < MAX_THREAD; i++){
        threads_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_increment, &threads_ids[i]);
    }

    for(int i = 0; i < MAX_THREAD; i++){
        pthread_join(threads[i], NULL);
    }

    printf("Number after increment: %d\n", number);
    
    return 0;
}