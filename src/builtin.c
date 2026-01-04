/*
   \def builtin.c
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

#include "snow/snow.h"

#include "snow/environment.h"
#include "snow/allocate.h"
#include "snow/object.h"

#include "snow/builtin.h"

SNOW_EXTERN_C_BEGIN

/* Helper to get Nth argument */
static SNObject_ref get_arg( SNObject_ref args, int index ) {
    SNObject_ref curr = args;
    for ( int i = 0; i < index; ++i ) {
        if ( curr == SNOW_NIL || ( (struct snow_lisp_val_s *)curr )->type_id != SNOW_TYPE_CONS ) {
            return SNOW_NIL;
        }
        curr = ( (SNCons_ref)curr )->cdr;
    }
    if ( curr != SNOW_NIL && ( (struct snow_lisp_val_s *)curr )->type_id == SNOW_TYPE_CONS ) {
        return ( (SNCons_ref)curr )->car;
    }
    return SNOW_NIL;
}

SNOW_API SNObject_ref snow_builtin_car( SNOW_ENV, SNObject_ref args ) {
    SNObject_ref obj = get_arg( args, 0 );
    if ( obj != SNOW_NIL && ( (struct snow_lisp_val_s *)obj )->type_id == SNOW_TYPE_CONS ) {
        return ( (SNCons_ref)obj )->car;
    }
    return SNOW_NIL;
}

SNOW_API SNObject_ref snow_builtin_cdr( SNOW_ENV, SNObject_ref args ) {
    SNObject_ref obj = get_arg( args, 0 );
    if ( obj != SNOW_NIL && ( (struct snow_lisp_val_s *)obj )->type_id == SNOW_TYPE_CONS ) {
        return ( (SNCons_ref)obj )->cdr;
    }
    return SNOW_NIL;
}

SNOW_API SNObject_ref snow_builtin_cons( SNOW_ENV, SNObject_ref args ) {
    SNObject_ref car = get_arg( args, 0 );
    SNObject_ref cdr = get_arg( args, 1 );
    return snow_make_cons( env, car, cdr );
}

SNOW_EXTERN_C_END

// Local Variables:
//   coding: utf-8
// End:
