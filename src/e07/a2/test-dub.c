#include <stdio.h>
#include "e07/list.h"

int dub(list);

int main(void) {
    list l = prompt_list();
    printf("dub(<>) = ");
    print_list(l);
    free_list(l);
}

