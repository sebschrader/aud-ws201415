#include <stdlib.h>
#include "e07/list.h"

/**
 * Insert a new value into a sorted list and return a new head pointer if
 * necessary.
 *
 * This solution is recursive and avoids using a double pointer.
 */
struct elem *insert(struct elem *l, int i) {
    if (l == NULL || l->value >= i) {
        struct elem *new_elem = malloc(sizeof(struct elem));
        new_elem->value = i;
        new_elem->next = l;
        return new_elem;
    } else {
        l->next = insert(l->next, i);
        return l;
    }
}

