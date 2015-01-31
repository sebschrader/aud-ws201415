#include<stdio.h>

/**
 * Ask the user if more contacts shall be read.
 *
 * This function is not required. It was added only for convenience.
 */
int shallContinue() {
    while(1) {
        printf("Read more [Y/N]? ");
        char answer;
        // Skip all whitespace and read a single character.
        if (scanf(" %c", &answer) != 1) {
            return 0;
        }
        switch(answer) {
            case 'y':
            case 'Y':
                return 1;
            case 'n':
            case 'N':
                return 0;
        }
        // Skip any input until newline
        scanf("%*[^\n]%*c");
    }
}

