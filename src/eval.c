#include "config.h"
#include <snow/eval.h>
#include <snow/object.h>

SNOW_EXTERN_C_BEGIN

SNOW_API SNObject_ref snow_eval(SNOW_ENV, SNObject_ref form) {
    if (form == SNOW_NIL) return SNOW_NIL;

    // Minimal eval: if symbol, lookup (not implemented). if cons, apply (not implemented).
    // if self-evaluating (not implemented), return self.

    // For now, just return the form.
    return form;
}

SNOW_EXTERN_C_END
