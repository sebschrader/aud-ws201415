#ifndef __LIST_H__
#define __LIST_H__

typedef struct elem *list;
typedef struct elem {
    int value;
    list next;
} elem;

list parse_list(const char *);

list prompt_list(void);

void print_list(list);

void free_list(list);

#endif

