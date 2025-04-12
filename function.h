#ifndef FUNCTION_H
#define FUNCTION_H

#include <pthread.h>
#include <stdio.h>

#define MAX_INCREMENTS 10000

extern int number;

extern pthread_mutex_t lock;

void* thread_increment(void* arg);

void* thread_increment_mutex(void* arg);

#endif