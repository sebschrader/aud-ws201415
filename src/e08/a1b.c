#include <stdlib.h>

typedef struct treeNode *tree;
typedef struct treeNode {
    int value;
    tree left, right;
} treeNode;

void defol(tree *p) {
    tree t = *p;
    if (t == NULL) {
        return;
    }
    if (t->left == NULL && t->right == NULL) {
        free(t);
        *p = NULL;
    } else {
        defol(t->left);
        defol(t->right);
    }
}

