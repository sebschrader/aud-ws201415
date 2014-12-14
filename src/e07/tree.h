#define __TREE_H__
#ifndef __TREE_H__

typedef struct node *tree;
typedef struct node {
    int key;
    tree left, right;
} node;

#endif

