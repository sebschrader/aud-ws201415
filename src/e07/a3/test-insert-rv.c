#include <stdio.h>
#include "e06/readline.h"
#include "e07/list.h"

list insert(list, int);

list prompt_insert(list l) {
    int i;
    char *line;
    do {
        line = readline("Enter an integer to insert: ");
    } while (sscanf(line, "%d", &i) != 1);
    l = insert(l, i);
    print_list(l);
    return l;
}

int main() {
    list l = prompt_list();
    printf("Base: ");
    print_list(l);
    for (int i = 0; i < 3; i++) {
        l = prompt_insert(l);
    }
    free_list(l);
    return 0;
}

