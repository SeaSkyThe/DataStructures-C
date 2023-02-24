#include <stdbool.h>

typedef struct Queue {
    void **memory;
    int allocated;
    int front;
    int back;
} Queue;

Queue *initializeQueue();

bool isEmpty(Queue *queue);

int size(Queue *queue);

void print(Queue *queue);

void enter(Queue *queue, void *data);

void *leave(Queue *queue);
