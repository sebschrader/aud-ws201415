#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <errno.h>
#include "e06/readline.h"
#include "tree.h"

typedef struct parse_info {
    const char *str;
    size_t len;
    int pos;
} parser_t;

enum parser_errors { PARSER_OK, PARSER_EOF, PARSER_MISMATCH, PARSER_MALLOC };

void parser_error(parser_t *p, const char *msg, ...) {
    fprintf(stderr, "Parse error in position %d: ", p->pos);
    va_list ap;
    va_start(ap, msg);
    vfprintf(stderr, msg, ap);
    va_end(ap);
    fprintf(stderr, "\n");
}

static inline int parser_peek(parser_t *p, char *c) {
    if (p->pos == p->len) return PARSER_EOF;
    *c = p->str[p->pos];
    return PARSER_OK;
}

static inline void parser_eat_space(parser_t *p) {
    while(isspace(p->str[p->pos])) p->pos++;
}

static inline int parser_eat_char(parser_t *p) {
    if (p->pos == p->len) return PARSER_EOF;
    p->pos++;
    return PARSER_OK;
}

static inline int parser_expect_char(parser_t *p, char expected) {
    char got;
    int rc;
    if ((rc = parser_peek(p, &got)) == PARSER_EOF) {
        parser_error(p, "expected '%c', reached end of input", expected);
        return rc;
    }
    if (expected != got) {
        parser_error(p, "expected '%c', got '%c'", expected, got);
        return PARSER_MISMATCH;
    }
    return parser_eat_char(p);
}

static inline int parser_read_int(parser_t *p, int *v) {
    long n;
    const char *start = p->str + p->pos;
    char *end;
    n = strtol(start, &end, 10);
    ptrdiff_t diff = end - start;
    if (diff == 0) {
        parser_error(p, "expected int");
        return PARSER_MISMATCH;
    }
    p->pos += diff;
    *v = n;
    return PARSER_OK;
}

int parser_read_tree(parser_t *p, tree *t) {
    int rc;
    parser_eat_space(p);
    if ((rc = parser_expect_char(p, '(')) != PARSER_OK) return rc;
    parser_eat_space(p);
    char next;
    if ((rc = parser_peek(p, &next)) != PARSER_OK) return rc;
    if (next == ')') {
        parser_eat_char(p);
        *t = NULL;
        return PARSER_OK;
    }
    parser_eat_space(p);
    int key;
    if ((rc = parser_read_int(p, &key)) != PARSER_OK) return rc;
    parser_eat_space(p);
    tree left;
    if ((rc = parser_read_tree(p, &left)) != PARSER_OK) return rc;
    parser_eat_space(p);
    tree right;
    if ((rc = parser_read_tree(p, &right)) != PARSER_OK) return rc;
    parser_eat_space(p);
    if ((rc = parser_expect_char(p, ')')) != PARSER_OK) return rc;
    tree new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        parser_error(p, strerror(errno));
        return PARSER_MALLOC;
    }
    new_node->key = key;
    new_node->left = left;
    new_node->right = right;
    *t = new_node;
    return PARSER_OK;
}

int parse_tree(tree *t, const char *line) {
    parser_t p = { line, strlen(line), 0 };
    return parser_read_tree(&p, t);
}

tree prompt_tree(void) {
    tree t = NULL;
    int rv;
    do {
        char *line = readline("Specify a tree using S-expressions; () denotes the empty node; e.g. (1 (-3 () ()) ()):\n");
        rv = parse_tree(&t, line);
        free(line);
    } while(rv != PARSER_OK);
    return t;
}

void print_tree_node(tree t) {
    if (t == NULL) {
        printf("()");
        return;
    }
    printf("(%d ", t->key);
    print_tree_node(t->left);
    printf(" ");
    print_tree_node(t->right);
    printf(")");
}

void print_tree(tree t) {
    print_tree_node(t);
    printf("\n");
}

void free_tree(tree t) {
    if (t == NULL) return;
    tree left  = t->left;
    tree right = t->right;
    free(t);
    free_tree(left);
    free_tree(right);
}


