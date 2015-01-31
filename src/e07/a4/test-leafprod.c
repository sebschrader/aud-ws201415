#include <stdio.h>
#include "e07/tree.h"

int leafprod(tree);

int main(void) {
    tree t = prompt_tree();
    printf("t = ");
    print_tree(t);
    printf("leafprod(t) = %d\n", leafprod(t));
    free_tree(t);
    return 0;
}

