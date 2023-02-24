#include <stdbool.h>
/** @struct Stack
 *  @brief This structure implements a basic generic stack.
 *  @var Stack:: memory
 *  Member 'memory' is a pointer to the the stacks memory.
 *  @var Stack:: allocated
 *  Member 'allocated' holds the current allocated size of the stack.
 *  @var Stack::top
 *  Member 'top' holds the index to the top most stored item.
 *  @var Stack::freeItem
 *  Member 'freeItem' the freeing item function pointer
 */

typedef struct Stack {
    void **memory;
    int allocated;
    int top;
} Stack;

Stack *initializeStack();

bool isEmpty(Stack *stack);

int size(Stack *stack);

void print(Stack *stack);

void push(Stack *stack, void *data);

void *pop(Stack *stack);
