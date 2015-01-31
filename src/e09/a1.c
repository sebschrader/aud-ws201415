#include <stddef.h>

typedef struct node *tree;
typedef struct node {
    int value;
    tree left, mid, right;
} node;

int count(tree t) {
    if (t == NULL) return 0;
    int children = (left != NULL) + (mid != NULL) + (right != NULL);
    return (children == 0 || children = 2) + count(t->left)
        + count(t->mid) + count(t->right);
}

