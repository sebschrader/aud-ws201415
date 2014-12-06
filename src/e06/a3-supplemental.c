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
    char *step_start;
    do {
        sz += STEP_SIZE;
        // Grow the buffer and leave space for the trailing NUL byte
        buf = realloc(buf, sz + 1);
        if (buf == NULL) {
            perror("realloc() failed");
            return NULL;
        }
        step_start = buf + sz - STEP_SIZE;
        memset(step_start, 0, STEP_SIZE + 1);
        if (scanf("%" XSTR(STEP_SIZE) "[^\n]", step_start) != 1) {
            // There was an error during scanf
            break;
        }
    } while(strlen(step_start) == STEP_SIZE);
    // Discard the newline character
    scanf("%*c");
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

