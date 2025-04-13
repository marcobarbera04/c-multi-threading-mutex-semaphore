#ifndef FUNCTION_H
#define FUNCTION_H

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_INCREMENTS 10000
#define BUFFER_SIZE 2

extern int number;

extern int numbers[];

extern pthread_mutex_t lock;

extern sem_t sem;

void* thread_increment(void* arg);

void* thread_increment_mutex(void* arg);

void* thread_buffer_reading_semaphore(void* arg);

#endif