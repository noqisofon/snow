#include "config.h"
#include <stdio.h>
#include <snow/snow.h>
#include <snow/read.h>
#include <snow/eval.h>
#include <snow/print.h>
#include <snow/environment.h>
#include <snow/object.h>

int main(int argc, char** argv) {
    printf("Welcome to snow Lisp!\n");

    // Create actual environment
    SNEnvironment_ref env = snow_env_create(NULL);

    // Test: bind 'x' to 'foo'
    SNObject_ref sym_x = snow_make_symbol(env, "x");
    SNObject_ref sym_foo = snow_make_symbol(env, "foo");
    snow_env_bind(env, sym_x, sym_foo);

    while (1) {
        printf("> ");
        fflush(stdout);
        SNObject_ref expr = snow_read(env, stdin);
        if (feof(stdin)) {
            break;
        }

        SNObject_ref result = snow_eval(env, expr);
        snow_print(env, result);
        printf("\n");
    }

    return 0;
}
