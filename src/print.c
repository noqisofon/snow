#include "config.h"
#include <snow/print.h>
#include <snow/object.h>
#include <stdio.h>

SNOW_EXTERN_C_BEGIN

void snow_print(SNOW_ENV, SNObject_ref obj) {
    if (obj == SNOW_NIL) {
        printf("NIL");
        return;
    }

    switch (obj->type_id) {
        case SNOW_TYPE_CONS:
            printf("(");
            snow_print(env, ((SNCons_ref)obj)->car);
            printf(" . ");
            snow_print(env, ((SNCons_ref)obj)->cdr);
            printf(")");
            break;
        case SNOW_TYPE_SYMBOL:
            printf("%s", ((struct snow_symbol_s*)obj)->name);
            break;
        default:
            printf("#<Unknown>");
            break;
    }
}

SNOW_EXTERN_C_END
