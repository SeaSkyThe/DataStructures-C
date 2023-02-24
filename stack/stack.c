#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

Stack *initializeStack() {
    Stack *stack = malloc(sizeof(Stack));

    if (stack == NULL) {
        printf("\nFAILED ALLOCATION\n");
        return NULL;
    }

    stack->allocated = 10;
    stack->memory = (void **)malloc(sizeof(void *) * stack->allocated);
    return stack;
}

bool isEmpty(Stack *stack) {
    if (stack != NULL) {
        if (stack->top == 0) {
            return true;
        }
        return false;
    }
    return NULL;
}

int size(Stack *stack) {
    if (stack != NULL) {
        return stack->top;
    }
}

void print(Stack *stack) {
    if (stack != NULL) {
        int i = stack->top - 1;
        printf("\n STACK: \n");
        for (; i >= 0; i--) {
            printf(" %p\n", *(stack->memory + i));
        }
    }
    return;
}

void push(Stack *stack, void *data) {
    if (stack != NULL) {
        if (stack->allocated - 1 == stack->top) {
            stack->allocated *= 2;
            stack->memory = (void **)realloc(stack->memory, sizeof(void *) * stack->allocated);
        }

        if (stack->memory != NULL) {
            *(stack->memory + stack->top) = data;
            stack->top = stack->top + 1;
        }
    }
}

void *pop(Stack *stack) {
    if (stack != NULL) {
        if (!isEmpty(stack)) {
            stack->top = stack->top - 1;
            return *(stack->memory + stack->top + 1);
        }
    }
}
void main() {
    // TESTS

    Stack *stack = initializeStack();
    push(stack, (void *)5);
    push(stack, (void *)6);
    push(stack, (void *)2);
    pop(stack);
    pop(stack);

    print(stack);
}