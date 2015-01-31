#include <stdlib.h>
#include <stdio.h>
#include "e06/readline.h"
#include "list.h"

//==========
// IMPORTANT
//==========
// The functions implemented in this file are NOT mandatory for the
// assignments. They are just convenient helper functions that enable
// writing short test programs.

/**
 * Parse a list of space separated integers to turn it into a list.
 */
list parse_list(const char *line) {
    const char *start = line;
    struct elem *head = NULL;
    struct elem **prev = &head;
    int value;
    int read;
    while(sscanf(start, " %i%n", &value, &read) == 1) {
        list new_elem = malloc(sizeof(elem));
        *prev = new_elem;
        new_elem->value = value;
        new_elem->next = NULL;
        prev = &(new_elem->next);
        start += read;
    }
    return head;
}

/**
 * Prompt the user on stdout to input a space separated list of integers on
 * stdin.
 */
list prompt_list(void) {
    char *line = readline("Enter a space separated list of integers, e.g. 1 -5 12 3:\n");
    list l = parse_list(line);
    free(line);
    return l;
}

/**
 * Print the contents of a integer list on stdout
 */
void print_list(list l) {
    for (; l != NULL; l = l->next) {
        printf("%d ", l->value);
    }
    printf("\n");
}

/**
 * Free a whole list.
 */
void free_list(list l) {
    while(l != NULL) {
        list next = l->next;
        free(l);
        l = next;
    }
}

