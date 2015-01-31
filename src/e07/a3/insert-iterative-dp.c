#include <stdlib.h>
#include "e07/list.h"

// We could use the typedef'ed names of our custom list type, but we won't do
// it in this file to not obfuscate the real type.

/**
 * Insert a new value into a sorted list.
 *
 * This solution is iterative and uses a double-pointer argument to change the
 * head pointer of the list if necessary.
 */
void insert(struct elem **l, int i) {
    struct elem **prev = l;
    struct elem *cur = *l;
    while(cur != NULL && cur->value < i) {
        prev = &(cur->next);
        cur = cur->next;
    }
    struct elem *new_elem = malloc(sizeof(struct elem));
    new_elem->value = i;
    new_elem->next = cur;
    *prev = new_elem;
}

