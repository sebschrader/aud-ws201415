#include <stdlib.h>
#include "e07/list.h"

int sum(list l) {
    int s = 0;
    for (list e = l; e != NULL; e = e->next) {
        s += e->value;
    }
    return s;
}

