#include "config.h"
#include <snow/read.h>
#include <snow/object.h>
#include <snow/allocate.h>
#include <ctype.h>
#include <string.h>

SNOW_EXTERN_C_BEGIN

static int peek_char(FILE* stream) {
    int c = getc(stream);
    ungetc(c, stream);
    return c;
}

static void skip_whitespace(FILE* stream) {
    int c;
    while ((c = getc(stream)) != EOF) {
        if (!isspace(c)) {
            ungetc(c, stream);
            break;
        }
    }
}

SNOW_API SNObject_ref snow_read(SNOW_ENV, FILE* stream) {
    skip_whitespace(stream);
    int c = getc(stream);

    if (c == EOF) return SNOW_NIL;

    if (c == '(') {
        // Read list
        SNObject_ref head = SNOW_NIL;
        SNObject_ref tail = SNOW_NIL;

        skip_whitespace(stream);
        if (peek_char(stream) == ')') {
            getc(stream); // consume ')'
            return SNOW_NIL;
        }

        while (1) {
             skip_whitespace(stream);
             if (peek_char(stream) == ')') {
                 getc(stream);
                 break;
             }
             if (peek_char(stream) == '.') {
                 getc(stream); // consume '.'
                 SNObject_ref last = snow_read(env, stream);
                 if (tail) {
                    ((SNCons_ref)tail)->cdr = last;
                 } else {
                    head = last; // Should not happen for proper dotted pair (A . B)
                 }
                 skip_whitespace(stream);
                 if (peek_char(stream) == ')') {
                    getc(stream);
                 }
                 break;
             }

             SNObject_ref elem = snow_read(env, stream);
             SNObject_ref new_node = snow_make_cons(env, elem, SNOW_NIL);
             if (head == SNOW_NIL) {
                 head = new_node;
                 tail = head;
             } else {
                 ((SNCons_ref)tail)->cdr = new_node;
                 tail = new_node;
             }
        }
        return head;
    } else if (c == ')') {
        return SNOW_NIL; // Should be error if unmatched
    } else {
        // Symbol or Number
        char buffer[256];
        int i = 0;
        buffer[i++] = c;
        while ((c = getc(stream)) != EOF) {
            if (isspace(c) || c == '(' || c == ')') {
                ungetc(c, stream);
                break;
            }
            if (i < 255) buffer[i++] = c;
        }
        buffer[i] = '\0';

        if (strcmp(buffer, "nil") == 0 || strcmp(buffer, "NIL") == 0) {
            return SNOW_NIL;
        }

        return snow_make_symbol(env, buffer);
    }
}

SNOW_EXTERN_C_END
