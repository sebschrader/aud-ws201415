#include <stdio.h>
#include "e07/tree.h"

tree baz(tree, tree);

int main(void) {
    tree s = prompt_tree();
    printf("s = ");
    print_tree(s);
    tree t = prompt_tree();
    printf("t = ");
    print_tree(t);
    tree r = baz(s, t);
    printf("baz(s, t) = ");
    print_tree(r);
    free_tree(r);
    free_tree(s);
    free_tree(t);
    return 0;
}

