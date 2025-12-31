/* 
     object.c   - data structures
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
#   include <stddef.h>
#endif  /* def HAVE_STDDEF_H */
#ifdef HAVE_STDINT_H
#   include <stdint.h>
#endif  /* def HAVE_STDINT_H */
#include <string.h>

#include "snow/snow.h"

#include "snow/environment.h"
#include "snow/allocate.h"

#include "snow/object.h"


SNOW_EXTERN_C_BEGIN


static SNObject_ref snow_make_instance(SNOW_ENV, uint8_t type_id)
{
    SNObject_ref ret = SNOW_NIL;

    switch ( type_id ) {
        case SNOW_TYPE_SYMBOL:
            ret = (SNObject_ref)snow_malloc(env, sizeof(struct snow_symbol_s) );
            SNOW_SET_TYPEID(ret, type_id);
            break;

        case SNOW_TYPE_CONS:
            ret = (SNObject_ref)snow_malloc(env, sizeof(struct snow_cons_s) );
            SNOW_SET_TYPEID(ret, type_id);
            break;

        default:
            ret = SNOW_NIL;
    }

    return ret;
}


SNOW_API SNObject_ref snow_make_cons(SNOW_ENV, SNObject_ref car, SNObject_ref cdr)
{
    SNCons_ref c = (SNCons_ref)snow_make_instance(env, SNOW_TYPE_CONS );
    c->car = car;
    c->cdr = cdr;
    return (SNObject_ref)c;
}

SNOW_API SNObject_ref snow_make_symbol(SNOW_ENV, const char* name)
{
    struct snow_symbol_s* sym = (struct snow_symbol_s*)snow_make_instance(env, SNOW_TYPE_SYMBOL);
    // Duplicate string
    if (name) {
        size_t len = strlen(name);
        sym->name = (char*)snow_malloc(env, len + 1);
        strcpy(sym->name, name);
    } else {
        sym->name = NULL;
    }
    return (SNObject_ref)sym;
}


SNOW_EXTERN_C_END
// Local Variables:
//   coding: utf-8
// End:
