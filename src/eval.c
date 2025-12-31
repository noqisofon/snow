#include "config.h"
#include <snow/eval.h>
#include <snow/object.h>
#include <snow/environment.h>

SNOW_EXTERN_C_BEGIN

SNOW_API SNObject_ref snow_eval(SNOW_ENV, SNObject_ref form) {
    if (form == SNOW_NIL) {
        return SNOW_NIL;
    }

    if (form->type_id == SNOW_TYPE_SYMBOL) {
        // Variable lookup
        SNObject_ref val = snow_env_lookup(env, form);
        // If not found, currently returns NIL. In real Lisp, this is an error.
        // But for now, returning NIL or self might be confusing.
        // Let's assume NIL means unbound for this simple stage, or just return the result.
        // Actually, if it's not found, maybe we should print a warning?
        // Or for now, just return NIL if not found.
        return val;
    }

    // Self-evaluating objects (Cons, numbers, etc. - Cons should be function call but not yet implemented)
    // For now, Cons evaluates to itself (like quote)

    return form;
}

SNOW_EXTERN_C_END
