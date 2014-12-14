#include <stdlib.h>
#include "e07/tree.h"

int count(tree t, int n) {
    if (t == NULL) return 0;
    return (t->key == n) + count(t->left) + count(t->right);
}

tree baz(tree s, tree t) {
    if (s == NULL) return NULL;
    tree r = malloc(sizeof(node));
    r->key = count(t, s->key);
    r->left = baz(s->left, t);
    r->right = baz(s->right, t);
    return r;
}

