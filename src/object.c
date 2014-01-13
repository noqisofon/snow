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

#include "snow/allocate.h"
#include "snow/object.h"


_BEGIN_C_EXTERN


static snow_object snow_make_instace(uint8_t type_id)
{
    snow_object ret;

    switch ( type_id ) {
        case snow_t_symbol:
            ret = snow_alloc( sizeof(struct snow_symbol) );
            SNOW_SET_TYPEID(ret, snow_t_symbol);

        case snow_t_cons:
            ret = snow_alloc( sizeof(struct snow_cons) );
            SNOW_SET_TYPEID(ret, snow_t_cons);

        default:
            ret = SNOW_NIL;
    }

    return ret;
}


SNOW_API snow_object snow_make_cons(SNOW_ENV)
{
    return snow_make_instance( snow_t_cons );
}


_END_C_EXTERN


#endif  /* object_h */
// Local Variables:
//   coding: utf-8
// End:

