#include <stdio.h>
#include "e07/list.h"

int sum(list);

int main(void) {
    list l = prompt_list();
    printf("sum(<>) = %d\n", sum(l));
    free_list(l);
}

