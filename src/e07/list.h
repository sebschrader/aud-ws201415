#ifndef __LIST_H__
#define __LIST_H__

typedef struct elem *list;
typedef struct elem {
    int value;
    list next;
} elem;

list parse_list(const char *);

void print_list(list);

#endif

