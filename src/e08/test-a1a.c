#include <stdio.h>
#include "e07/list.h"
#include "a1a.c"

int main(void) {
    list l = prompt_list();
    printf("l = ");
    print_list(l);
    printf("f(l) = %d\n", f(l));
    free_list(l);
    return 0;
}

