#include <stdlib.h>
#include "e07/tree.h"

int leafprod(tree t) {
    if (t == NULL) return 1;
    if (t->left == NULL && t->right == NULL) return t->key;
    return leafprod(t->left) * leafprod(t->right);
}

