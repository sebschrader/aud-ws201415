#include <stdlib.h>
#include "e07/list.h"

struct elem *insert(struct elem *l, int i) {
    struct elem *new_elem = malloc(sizeof(struct elem));
    new_elem->value = i;
    // Handle head-insert specially
    if (l == NULL || l->value > i) {
        new_elem->next = l;
        return new_elem;
    }
    // Otherwise search for proper insertion point and return the original head
    struct elem *prev = l;
    struct elem *cur = l->next;
    while(cur != NULL && cur->value < i) {
        prev = cur;
        cur = cur->next;
    }
    new_elem->next = cur;
    prev->next = new_elem;
    return l;
}

