#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XSTR(s) STR(s)
#define STR(s) #s
#define STEP_SIZE 10


/**
 * Read an entire line from standard input and return an buffer allocated that
 * must be freed using free(). The newline character is NOT stored in the
 * buffer. The string is terminated with a NUL byte. NULL is returned, if an
 * read error occurred.
 *
 * The POSIX.1-2008 standard defines a similar function. But not any C-Standard
 * unfortunately.
 */
char *getline() {
    size_t sz = 0;
    char *buf = NULL;
    char *start;
    do {
        sz += STEP_SIZE;
        buf = realloc(buf, sz + 1);
        start = buf + sz;
        memset(buf + sz - STEP_SIZE, 0, STEP_SIZE + 1);
        if (scanf("%" XSTR(STEP_SIZE) "[^\n]%*c", buf + sz - STEP_SIZE) != 1) {
            // There was an error during scanf
            break;
        }
    } while(strlen(buf + sz - STEP_SIZE) == STEP_SIZE);
    return buf;
}


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

