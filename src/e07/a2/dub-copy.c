#include <stdlib.h>
#include "e07/list.h"

/**
 * Create a new list with all values of the source list doubled.
 */
list dub(list l) {
    list new_head;
    list *prev = &new_head;

    for (list cur = l; cur != NULL; cur = cur->next) {
        list new_elem = malloc(sizeof(elem));
        *prev = new_elem;
        new_elem->value = cur->value * 2;
        new_elem->next = NULL;
        prev = &(new_elem->next);
    }
    return new_head;
}

/**
 * Same as dub, but recursive.
 */
list dub2(list l) {
    if (l == NULL) {
        return NULL;
    }
    list new_elem = malloc(sizeof(elem));
    new_elem->value = l->value * 2;
    new_elem->next = dub2(l);
    return new_elem;
}

