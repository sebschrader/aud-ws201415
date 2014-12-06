#include <stdlib.h>
#include "e07/list.h"

list dub(list l) {
    for (list i = l; i != NULL; i = i->next) {
        i->value *= 2;
    }
    return l;
}

