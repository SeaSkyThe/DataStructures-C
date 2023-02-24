#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue *initializeQueue() {
    Queue *queue = malloc(sizeof(Queue));

    if (queue == NULL) {
        printf("\nFAILED ALLOCATION\n");
        return NULL;
    }

    queue->allocated = 10;
    queue->memory = (void **)malloc(sizeof(void *) * queue->allocated);
    return queue;
}

bool isEmpty(Queue *queue) {
    if (queue != NULL) {
        if (queue->back == queue->front) {
            return true;
        }
        return false;
    }
    return NULL;
}

int size(Queue *queue) {
    if (queue != NULL) {
        return queue->back;
    }
}

void print(Queue *queue) {
    if (queue != NULL) {
        int i = queue->front;
        printf("\n QUEUE: \n");
        for (; i < queue->back; i++) {
            printf(" %d ", *(queue->memory + i));
        }
        printf("\n");
    }
    return;
}

void enter(Queue *queue, void *data) {
    if (queue != NULL) {
        if (queue->allocated == queue->back) {
            queue->allocated *= 2;

            void **tempArr = (void **)malloc(sizeof(void *) * queue->allocated);
            if (tempArr != NULL) {
                memcpy(tempArr, queue->memory + queue->front,
                       sizeof(void *) * (queue->back - queue->front));
                // free(queue->memory);
                queue->memory = tempArr;
                queue->back -= queue->front;
                queue->front = 0;
            }
        }

        if (queue->memory != NULL) {
            *(queue->memory + queue->back) = data;
            queue->back = queue->back + 1;
        }
    }
}

void *leave(Queue *queue) {
    if (queue != NULL) {
        if (!isEmpty(queue)) {
            queue->front = queue->front + 1;
            return *(queue->memory + queue->front - 1);
        }
    }
}
void main() {
    // TESTS

    Queue *queue = initializeQueue();
    enter(queue, (void *)1);
    enter(queue, (void *)2);
    enter(queue, (void *)3);

    enter(queue, (void *)4);
    enter(queue, (void *)5);
    enter(queue, (void *)6);

    enter(queue, (void *)7);
    enter(queue, (void *)8);
    enter(queue, (void *)9);

    enter(queue, (void *)10);
    enter(queue, (void *)11);

    enter(queue, (void *)12);
    enter(queue, (void *)13);

    print(queue);

    leave(queue);
    leave(queue);

    print(queue);
}