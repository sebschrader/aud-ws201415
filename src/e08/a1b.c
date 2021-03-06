#include <stdlib.h>
#include "e07/tree.h"

/*
typedef struct treeNode *tree;
typedef struct treeNode {
    int value;
    tree left, right;
} treeNode;
*/

void defol(tree *p) {
    // Dereferencing p once and storing it in a local variable t makes the
    // code a bit easier to read.
    tree t = *p;
    if (t == NULL) {
        return;
    }
    // Check for leaf node
    if (t->left == NULL && t->right == NULL) {
        free(t);
        // Setting *p NULL is very important, otherwise later tree traversals
        // won't be able to detect that there is no child node anymore and use
        // free'd memory which is very bad.
        *p = NULL;
    } else {
        defol(&(t->left));
        defol(&(t->right));
    }
}

