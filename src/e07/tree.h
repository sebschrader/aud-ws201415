#ifndef __TREE_H__
#define __TREE_H__

typedef struct node *tree;
typedef struct node {
    int key;
    tree left, right;
} node;


int parse_tree(tree *, const char *);

tree prompt_tree(void);

void print_tree(tree);

void free_tree(tree);

#endif

