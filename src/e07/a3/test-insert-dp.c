#include <stdio.h>
#include "e07/list.h"

void insert(list *, int);

void print_insert(list *l, int i) {
    printf("Inserting %d: ", i);
    insert(l, i);
    print_list(*l);
}

int main() {
    list l = prompt_list();
    printf("Base: ");
    print_list(l);
    print_insert(&l, 7);
    print_insert(&l, -2);
    print_insert(&l, 4);
    free_list(l);
    return 0;
}

