#include "function.h"

#define MAX_THREAD 5

extern sem_t sem;

int main(){
    pthread_t threads[MAX_THREAD];
    int threads_ids[MAX_THREAD];

    sem_init(&sem, 0, 2);

    for(int i = 0; i < MAX_THREAD; i++){
        threads_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_buffer_reading_semaphore, &threads_ids[i]);
    }

    for(int i = 0; i < MAX_THREAD; i++){
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem);
    
    return 0;
}