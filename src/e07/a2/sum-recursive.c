#include <stdlib.h>
#include "e07/list.h"

int sum(list l) {
    if (l == NULL) return 0;
    return l->value + sum(l->next);
}

