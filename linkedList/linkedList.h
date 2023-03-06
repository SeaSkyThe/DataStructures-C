#include <stdbool.h>

typedef struct Node {
    void *value;
    struct Node *next;
} Node;

typedef struct List {
    Node *first;
    Node *last;
    int size;
} List;

List *initializeList();

bool isEmpty(List *list);

int size(List *list);

void print(List *list);

void add(List *list, void *data, int pos);

void *removePos(List *list, int pos);

void *removeItem(List *list, int item);

List *reverse(List *list);
