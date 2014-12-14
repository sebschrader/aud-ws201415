#ifndef __TREE_H__
#define __TREE_H__

typedef struct node *tree;
typedef struct node {
    int key;
    tree left, right;
} node;


tree parse_tree(const char *);

void print_tree(tree);

#endif

