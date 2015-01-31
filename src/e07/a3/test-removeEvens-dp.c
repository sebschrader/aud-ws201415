#include <stdio.h>
#include "e07/list.h"

void removeEvens(list *);

int main(void) {
    list l = prompt_list();
    printf("Got the following list: ");
    print_list(l);
    printf("Removing evens: ");
    removeEvens(&l);
    print_list(l);
    free_list(l);
    return 0;
}

