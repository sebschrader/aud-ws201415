#include <stdlib.h>
#include "e07/list.h"

// In this file, we'll use the typedef'ed versions of our custom list type.

/**
 * Remove all even values from a list.
 *
 * This solution is iterative and uses a double-pointer argument to be able to
 * delete the head of the list.
 */
void removeEvens(list *l) {
    // Note: list * is actually struct elem **
    list *prev = l;
    list cur = *prev;
    while (cur != NULL) {
        if (cur->value % 2 == 0) {
            list temp = cur;
            *prev = cur->next;
            cur = cur->next;
            free(temp);
        } else {
            prev = &(cur->next);
            cur = cur->next;
        }
    }
}


/**
 * Remove all even values from a list and return a new head if necessary.
 *
 * This solution is recursive and avoids using double-pointers.
 */
list removeEvens2(list l) {
    if (l == NULL) {
        return l;
    }
    if (l->value % 2 == 0) {
        list next = l->next;
        free(l);
        return removeEvens2(next);
    }
    l->next = removeEvens2(l->next);
    return l;
}

