#include <stdlib.h>
#include <stdio.h>
#include "list.h"


/**
 * Parse a list of space separated integers to turn it into a list.
 */
list parse_list(const char *line) {
    const char *start = line;
    struct elem *head = NULL;
    struct elem **prev = &head;
    int value;
    int read;
    while(sscanf(start, " %i%n", &value, &read) == 1) {
        list new_elem = malloc(sizeof(elem));
        *prev = new_elem;
        new_elem->value = value;
        new_elem->next = NULL;
        prev = &(new_elem->next);
        start += read;
    }
    return head;
}

void print_list(list l) {
    for (; l != NULL; l = l->next) {
        printf("%d ", l->value);
    }
    printf("\n");
}


