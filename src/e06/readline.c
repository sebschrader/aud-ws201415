#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e06/readline.h"

#define STEP_SIZE 10

/**
 * Read an entire line from standard input. A newline character is stored in
 * the buffer if no error or EOF is encountered before. The string is always
 * terminated with a NUL '\0' byte. The signature of this function is the same
 * as GNU readline(3) but without the sophisticated features like line-editing
 * capabilities and config files.
 *
 * Returns NULL if an error occurred or EOF was reached before any character
 * was read. Otherwise returns a buffer that should be passed to free(3) after
 * it is no longer needed.
 *
 * The POSIX.1-2008 standard defines the similar function getline(3) and there
 * is also GNU readline(3). Unfortunately both of them are not defined by any
 * C-Standard and therefore not platform independent.
 */
char *readline(const char *prompt) {
    size_t sz = 0;
    char *buf = NULL;
    char *step_start;
    printf(prompt);
    while(1) {
        sz += STEP_SIZE;
        // Grow the buffer and leave an additional space for the trailing NUL
        // byte
        buf = realloc(buf, sz + 1);
        if (NULL == buf) {
            perror("realloc() failed");
            return NULL;
        }
        step_start = buf + sz - STEP_SIZE;
        memset(step_start, 0, STEP_SIZE + 1);
        if (NULL == fgets(step_start, STEP_SIZE + 1, stdin)) {
            break;
        }
        size_t len = strlen(step_start);
        // Test if fgets hit a newline
        if (len != STEP_SIZE || step_start[STEP_SIZE - 1] == '\n') {
            // Remove newline
            step_start[len - 1] = '\0';
            break;
        }
    }
    return buf;
}


