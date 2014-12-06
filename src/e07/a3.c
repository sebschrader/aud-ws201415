#include <stdio.h>
#include "e07/list.h"

void insert(list *, int);
void removeEvens(list *);

void print_insert(list *l, int i) {
    printf("Inserting %d: ", i);
    insert(l, i);
    print_list(*l);
}

int main() {
    const char * list_string = "1 2 3 4 5 6";
    list l = parse_list(list_string);
    printf("Base: ");
    print_list(l);
    print_insert(&l, 7);
    print_insert(&l, -2);
    print_insert(&l, 4);
    printf("Removing evens: ");
    removeEvens(&l);
    print_list(l);
    return 0;
}

