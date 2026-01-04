/*!
  \file environment.c
*/
/*
 Auther:
      ned rihine <ned.rihine@gmail.com>

 Copyright (c) 2014 rihine All rights reserved.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "config.h"

#ifdef HAVE_STDDEF_H
#    include <stddef.h>
#endif /* def HAVE_STDDEF_H */
#ifdef HAVE_STDINT_H
#    include <stdint.h>
#endif /* def HAVE_STDINT_H */
#include <stdlib.h>
#include <string.h>

#include "snow/snow.h"
#include "snow/environment.h"
#include "snow/object.h"
#include "snow/allocate.h"

SNOW_EXTERN_C_BEGIN

SNOW_API SNEnvironment_ref snow_env_create( SNEnvironment_ref parent ) {
    SNEnvironment_ref new_env = (SNEnvironment_ref)snow_malloc( parent, sizeof( struct snow_env_s ) );
    if ( new_env ) {
        new_env->_disable_interrupts = 0;
        new_env->bindings            = SNOW_NIL;
        new_env->parent              = parent;
    }
    return new_env;
}

SNOW_API void snow_env_bind( SNEnvironment_ref env, SNObject_ref symbol, SNObject_ref value ) {
    if ( !env || !symbol ) {
        return;
    }

    // Check if it's already bound in the *current* frame to update it
    SNObject_ref pair = SNOW_NIL;
    SNObject_ref curr = env->bindings;

    while ( curr != SNOW_NIL && ( (struct snow_lisp_val_s *)curr )->type_id == SNOW_TYPE_CONS ) {
        SNObject_ref binding = ( (struct snow_cons_s *)curr )->car;
        if ( binding != SNOW_NIL && ( (struct snow_lisp_val_s *)binding )->type_id == SNOW_TYPE_CONS ) {
            SNObject_ref key = ( (struct snow_cons_s *)binding )->car;
            // Symbol equality check (pointer comparison for interned symbols?
            // We don't have interning yet, so need string comparison)
            if ( ( (struct snow_lisp_val_s *)key )->type_id == SNOW_TYPE_SYMBOL &&
                 ( (struct snow_lisp_val_s *)symbol )->type_id == SNOW_TYPE_SYMBOL ) {
                char *s1 = ( (struct snow_symbol_s *)key )->name;
                char *s2 = ( (struct snow_symbol_s *)symbol )->name;
                if ( s1 && s2 && strcmp( s1, s2 ) == 0 ) {
                    pair = binding;
                    break;
                }
            }
        }
        curr = ( (struct snow_cons_s *)curr )->cdr;
    }

    if ( pair != SNOW_NIL ) {
        // Update existing binding
        ( (struct snow_cons_s *)pair )->cdr = value;
    } else {
        // Add new binding
        // Note: passing env as first arg to snow_make_cons.
        // Our snow_make_cons takes (SNOW_ENV, car, cdr). SNOW_ENV is `const SNEnvironment_ref env`.
        // Here `env` is `SNEnvironment_ref`. Const qualification mismatch might be a warning but valid.
        // Also snow_make_cons allocates using snow_malloc which uses env.
        SNObject_ref new_pair = snow_make_cons( env, symbol, value );
        env->bindings         = snow_make_cons( env, new_pair, env->bindings );
    }
}

SNOW_API SNObject_ref snow_env_lookup( SNEnvironment_ref env, SNObject_ref symbol ) {
    SNEnvironment_ref curr_env = env;
    while ( curr_env ) {
        SNObject_ref curr_list = curr_env->bindings;
        while ( curr_list != SNOW_NIL && ( (struct snow_lisp_val_s *)curr_list )->type_id == SNOW_TYPE_CONS ) {
            SNObject_ref binding = ( (struct snow_cons_s *)curr_list )->car;
            if ( binding != SNOW_NIL && ( (struct snow_lisp_val_s *)binding )->type_id == SNOW_TYPE_CONS ) {
                SNObject_ref key = ( (struct snow_cons_s *)binding )->car;
                if ( ( (struct snow_lisp_val_s *)key )->type_id == SNOW_TYPE_SYMBOL &&
                     ( (struct snow_lisp_val_s *)symbol )->type_id == SNOW_TYPE_SYMBOL ) {
                    char *s1 = ( (struct snow_symbol_s *)key )->name;
                    char *s2 = ( (struct snow_symbol_s *)symbol )->name;
                    if ( s1 && s2 && strcmp( s1, s2 ) == 0 ) {
                        return ( (struct snow_cons_s *)binding )->cdr;
                    }
                }
            }
            curr_list = ( (struct snow_cons_s *)curr_list )->cdr;
        }
        curr_env = curr_env->parent;
    }
    return SNOW_NIL; // Not found (or return error object?)
}

SNOW_EXTERN_C_END

// Local Variables:
//   coding: utf-8
// End:
