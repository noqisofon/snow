#include "config.h"
#include <snow/eval.h>
#include <snow/object.h>
#include <snow/environment.h>
#include <string.h>

SNOW_EXTERN_C_BEGIN

static SNObject_ref eval_list(SNOW_ENV, SNObject_ref list) {
    if (list == SNOW_NIL) {
        return SNOW_NIL;
    }
    if (((struct snow_lisp_val_s*)list)->type_id != SNOW_TYPE_CONS) {
        return list; // Should not happen if list is proper
    }

    SNObject_ref car = ((SNCons_ref)list)->car;
    SNObject_ref cdr = ((SNCons_ref)list)->cdr;

    SNObject_ref evaluated_car = snow_eval(env, car);
    SNObject_ref evaluated_cdr = eval_list(env, cdr);

    return snow_make_cons(env, evaluated_car, evaluated_cdr);
}

// Helper to get Nth element of a list (simple version, returns NIL if out of bounds)
static SNObject_ref get_nth(SNObject_ref list, int n) {
    SNObject_ref curr = list;
    for (int i = 0; i < n; i++) {
        if (curr == SNOW_NIL || ((struct snow_lisp_val_s*)curr)->type_id != SNOW_TYPE_CONS) {
            return SNOW_NIL;
        }
        curr = ((SNCons_ref)curr)->cdr;
    }
    if (curr != SNOW_NIL && ((struct snow_lisp_val_s*)curr)->type_id == SNOW_TYPE_CONS) {
        return ((SNCons_ref)curr)->car;
    }
    return SNOW_NIL;
}

SNOW_API SNObject_ref snow_eval(SNOW_ENV, SNObject_ref form) {
    if (form == SNOW_NIL) {
        return SNOW_NIL;
    }

    if (form->type_id == SNOW_TYPE_SYMBOL) {
        // Variable lookup
        SNObject_ref val = snow_env_lookup(env, form);
        return val;
    }

    if (form->type_id == SNOW_TYPE_CONS) {
        // Function application or Special Form
        SNObject_ref fn_expr = ((SNCons_ref)form)->car;
        SNObject_ref args = ((SNCons_ref)form)->cdr;

        // Check for Special Forms (quote, if, setq) BEFORE evaluating operator
        // Since we don't have a robust symbol checking (no interning), string comparison for now.
        if (fn_expr->type_id == SNOW_TYPE_SYMBOL) {
            struct snow_symbol_s* sym = (struct snow_symbol_s*)fn_expr;
            if (sym->name) {
                if (strcmp(sym->name, "quote") == 0) {
                    // (quote expr) -> expr
                    if (args != SNOW_NIL && args->type_id == SNOW_TYPE_CONS) {
                        return ((SNCons_ref)args)->car;
                    }
                    return SNOW_NIL;
                }
                if (strcmp(sym->name, "if") == 0) {
                    // (if test then else)
                    SNObject_ref test_expr = get_nth(args, 0);
                    SNObject_ref then_expr = get_nth(args, 1);
                    SNObject_ref else_expr = get_nth(args, 2);

                    SNObject_ref test_val = snow_eval(env, test_expr);
                    if (test_val != SNOW_NIL) { // Non-NIL is true
                         return snow_eval(env, then_expr);
                    } else {
                         return snow_eval(env, else_expr);
                    }
                }
                if (strcmp(sym->name, "setq") == 0) {
                    // (setq symbol value)
                    SNObject_ref sym_expr = get_nth(args, 0);
                    SNObject_ref val_expr = get_nth(args, 1);

                    if (sym_expr && sym_expr->type_id == SNOW_TYPE_SYMBOL) {
                         SNObject_ref val = snow_eval(env, val_expr);
                         snow_env_bind(env, sym_expr, val);
                         return val;
                    }
                    return SNOW_NIL; // Error: first arg must be symbol
                }
            }
        }

        // 1. Evaluate operator
        SNObject_ref fn = snow_eval(env, fn_expr);

        // 2. Check if it is a builtin function
        if (fn != SNOW_NIL && ((struct snow_lisp_val_s*)fn)->type_id == SNOW_TYPE_BUILTIN) {
            // 3. Evaluate arguments
            SNObject_ref eval_args = eval_list(env, args);

            // 4. Apply
            struct snow_builtin_s* builtin = (struct snow_builtin_s*)fn;
            if (builtin->func) {
                return builtin->func(env, eval_args);
            }
        }

        // If not a function, for now just return the form or error.
        return form;
    }

    // Self-evaluating objects
    return form;
}

SNOW_EXTERN_C_END
