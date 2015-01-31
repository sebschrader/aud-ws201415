#include <stdio.h>
#include "e07/tree.h"
#include "a1b.c"

int main(void) {
    tree t = prompt_tree();
    printf("t = ");
    print_tree(t);
    printf("defol(t) = ");
    defol(&t);
    print_tree(t);
    free_tree(t);
    return 0;
}

