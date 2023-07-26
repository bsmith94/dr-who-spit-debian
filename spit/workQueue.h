#ifndef _WORKQUEUE_H
#define _WORKQUEUE_H

#include <stdlib.h>
#include <pthread.h>

typedef struct {
    char type;
    size_t id;
    size_t size;
} workQueueActionType;

typedef struct {
    size_t sz;
    size_t allocsz;
    size_t head;
    size_t tail;
    size_t finished;
    double startTime;
    size_t sizeSum;
    workQueueActionType *actions;
    pthread_mutex_t lock;
} workQueueType;

void workQueueInit(workQueueType *queue, const size_t size);

void workQueueFree(workQueueType *queue);

int workQueuePush(workQueueType *queue, workQueueActionType action);

int workQueuePop(workQueueType *queue, workQueueActionType *ret);

size_t workQueueNum(workQueueType *queue);

size_t workQueueFinished(workQueueType *queue);

size_t workQueueFinishedSize(workQueueType *queue);

size_t workQueuePopArray(workQueueType *queue, workQueueActionType *actionArray, const size_t size);


#endif
