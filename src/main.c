#include "config.h"
#include <stdio.h>
#include <snow/snow.h>
#include <snow/read.h>
#include <snow/eval.h>
#include <snow/print.h>

int main(int argc, char** argv) {
    printf("Welcome to snow Lisp!\n");

    // Environment dummy for now
    struct snow_env_s env_struct;
    SNEnvironment_ref env = &env_struct;

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
