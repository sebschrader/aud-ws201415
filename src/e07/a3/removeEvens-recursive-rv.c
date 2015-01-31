#include <stdlib.h>
#include "e07/list.h"

/**
 * Remove all even values from a list and return a new head if necessary.
 *
 * This solution is recursive and avoids using double-pointers.
 */
list removeEvens(list l) {
    if (l == NULL) {
        return l;
    }
    if (l->value % 2 == 0) {
        list next = l->next;
        free(l);
        return removeEvens(next);
    }
    l->next = removeEvens(l->next);
    return l;
}

