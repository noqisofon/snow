#include "config.h"
#include <stdio.h>
#include <snow/snow.h>
#include <snow/read.h>
#include <snow/eval.h>
#include <snow/print.h>
#include <snow/environment.h>
#include <snow/object.h>
#include <snow/builtin.h>

int main(int argc, char** argv) {
    printf("Welcome to snow Lisp!\n");

    // Create actual environment
    SNEnvironment_ref env = snow_env_create(NULL);

    // Register builtins
    snow_env_bind(env, snow_make_symbol(env, "car"), snow_make_builtin(env, snow_builtin_car, "car"));
    snow_env_bind(env, snow_make_symbol(env, "cdr"), snow_make_builtin(env, snow_builtin_cdr, "cdr"));
    snow_env_bind(env, snow_make_symbol(env, "cons"), snow_make_builtin(env, snow_builtin_cons, "cons"));

    // Bind 't' to 't' (self-evaluating truth)
    SNObject_ref t = snow_make_symbol(env, "t");
    snow_env_bind(env, t, t);

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
