#include <stdlib.h>
#include "e07/list.h"


// We won't use the data type definitions from the exercise, shown in the
// comment below, as they are equivalent to the ones defined in exercise 7.

/*
typedef struct listElement *list;
typedef struct listElement {
    int value;
    list next;
} listElement;
*/

int f(list l) {
    if (l == NULL) {
        return 1;
    }
    for (int last = l->value - 1; l != NULL; last = l->value, l = l->next) {
        // The C standard library includes an abs function, one could have
        // also written: last - l->value != 1 && last - l->value != -1
        if (abs(last - l->value) != 1) {
            return 0;
        }
    }
    return 1;
}

