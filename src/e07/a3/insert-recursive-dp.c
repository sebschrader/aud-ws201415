#include <stdlib.h>
#include "e07/list.h"

void insert(struct elem **p, int i) {
    struct elem *l = *p;
    if (l == NULL || l->value > i) {
        struct elem *e = malloc(sizeof(struct elem));
        e->value = i;
        e->next = l;
        *p = e;
    } else {
        insert(&(l->next), i);
    }
}

