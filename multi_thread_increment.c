#include <stdio.h>
#include <pthread.h>
#include "function.h"

#define MAX_THREAD 10

extern int number;

int main(){
    pthread_t threads[MAX_THREAD];

    printf("Numero prima dell' incremento: %d\n", number);

    for(int i = 0; i < MAX_THREAD; i++){
        pthread_create(&threads[i], NULL, thread_increment, &number);
    }

    for(int i = 0; i < MAX_THREAD; i++){
        pthread_join(threads[i], NULL);
    }

    printf("Numero dopo incremento: %d\n", number);
    
    return 0;
}