#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List *initializeList() {
    List *list = malloc(sizeof(List));

    if (list == NULL) {
        printf("\nFAILED ALLOCATION\n");
        return NULL;
    }

    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

bool is_empty(List *list) {
    if (list != NULL) {
        if (list->size == 0) {
            return true;
        }
        return false;
    }
    printf("\n VERIFY IF THE LIST WAS CORRECTLY ALLOCATED\n");
    return true;
}

int size(List *list) {
    if (list != NULL) {
        return list->size;
    }
    printf("\n VERIFY IF THE LIST WAS CORRECTLY ALLOCATED\n");
    return 0;
}

void print(List *list) {
    if (list != NULL) {
        Node *current_node = list->first;
        printf("[ ");
        while (current_node != NULL) {
            printf("%d ", current_node->value);
            current_node = current_node->next;
        }
        printf("]\n");
        return;
    }
    printf("\n VERIFY IF THE LIST WAS CORRECTLY ALLOCATED\n");
    return;
}

void add(List *list, void *data, int pos) {
    if (list != NULL) {
        if (list->size != 0) {
            int current_pos;
            Node *currrent_node = list->first;
            Node *new_node = malloc(sizeof(Node));
            new_node->value = data;
            for (current_pos = 0; current_pos <= list->size; current_pos++) {
                if (pos == 0 && current_pos == pos) {
                    new_node->next = currrent_node;
                    list->first = new_node;
                    list->size += 1;
                }
                if (current_pos == pos - 1) {
                    new_node->next = currrent_node->next;
                    currrent_node->next = new_node;

                    if (pos == list->size) {
                        list->last = new_node;
                    }
                    list->size += 1;
                    return;
                }

                if (currrent_node->next != NULL) {
                    currrent_node = currrent_node->next;
                } else {
                    return;
                }
            }
            return;
        } else {
            if (pos == 0) {
                Node *new_node = malloc(sizeof(Node));
                new_node->value = data;
                new_node->next = NULL;
                list->first = new_node;
                list->last = new_node;
                list->size = 1;
            }
            return;
        }
    }
    printf("\n VERIFY IF THE LIST WAS CORRECTLY ALLOCATED\n");
    return;
}
void *removePos(List *list, int pos) {
    if (list != NULL) {
        if (pos == 0) {
            Node *first = list->first;
            list->first = list->first->next;
            free(first);
            list->size = list->size - 1;
        } else if (pos == list->size - 1) {
            int i = 0;
            Node *penultimate = list->first;
            for (; i < list->size - 2; i++) {
                penultimate = penultimate->next;
            }
            Node *last = list->last;
            list->last = penultimate;
            penultimate->next = NULL;
            free(last);
            list->size = list->size - 1;
        } else {
            int current_pos;
            Node *current_node = list->first;
            for (current_pos = 0; current_pos < list->size; current_pos++) {
                if (current_pos == pos - 1) {
                    Node *node_to_remove = current_node->next;
                    current_node->next = node_to_remove->next;
                    free(node_to_remove);
                    list->size = list->size - 1;
                    return;
                }

                if (current_node->next != NULL) {
                    current_node = current_node->next;
                } else {
                    return;
                }
            }
        }
        return;
    }
    printf("\n VERIFY IF THE LIST WAS CORRECTLY ALLOCATED\n");
    return;
}

// TODO: SEGMENTATION FAULT PROBLEM
void *removeItem(List *list, int item) {
    Node *current = list->first;
    if (current->value == item) {
        list->first = current->next;
        free(current);
        return item;
    }
    while (current != NULL) {
        Node *next = current->next;
        if (next->value == item) {
            current->next = next->next;
            free(next);
            return item;
        }
        current = next;
    }
    return -1;
}

List *reverse(List *list) {
    Node *previous = NULL;
    Node *current = list->first;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    list->first = previous;
    return list;
}
void main() {
    List *lista = initializeList();
    add(lista, 1, 0);
    add(lista, 2, 1);
    add(lista, 3, 2);
    add(lista, 4, 3);
    add(lista, 5, 4);
    add(lista, 54, 0);

    // removeItem(lista, 1);
    removePos(lista, 2);
    removePos(lista, 4);

    print(lista);
    List *reversed = reverse(lista);
    print(reversed);
}