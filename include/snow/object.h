/* 
     object.h   - data structures
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
#ifndef object_h
#define object_h


typedef enum _snow_type_id {
    snow_t_nil          = 0,
    snow_t_object       = 1,
    snow_t_charater     = 2,
    snow_t_fixnum       = 3,

    snow_t_symbol       = (  1 << 2 ) | snow_t_object,
    snow_t_cons         = (  2 << 2 ) | snow_t_object,
    snow_t_string       = (  3 << 2 ) | snow_t_object,
    snow_t_vector       = (  4 << 2 ) | snow_t_object,
    snow_t_cfunction    = (  5 << 2 ) | snow_t_object,
    snow_t_cclosure     = (  6 << 2 ) | snow_t_object,

    snow_t_bignum       = (  7 << 2 ) | snow_t_object,
    snow_t_ration       = (  8 << 2 ) | snow_t_object,
    snow_t_single_float = (  9 << 2 ) | snow_t_object,
    snow_t_double_float = ( 10 << 2 ) | snow_t_object,
    snow_t_long_float   = ( 11 << 2 ) | snow_t_object,
    snow_t_complex      = ( 12 << 2 ) | snow_t_object,

    snow_t_namespace    = ( 13 << 2 ) | snow_t_object,
} snow_type_id;

typedef union snow_object*  snow_object;


#define SNOW_NIL                ((snow_object) NULL)

#define SNOW_TAG_BITS           2

#define SNOW_CHARACTER_TAG      snow_t_charater
#define SNOW_FIXNUM_TAG         snow_t_fixnum
#define SNOW_STRING_TAG         snow_t_string
#define SNOW_SYMBOL_TAG         snow_t_symbol

#define SNOW_HEADER             uint8_t _type_id; snow_object _base

struct snow_cons {
    SNOW_HEADER;

    snow_object   _car;
    snow_object   _cdr;
};
#define SNOW_CONS_CAR(_that_)       ((_that_)->_cons._car)
#define SNOW_CONS_CDR(_that_)       ((_that_)->_cons._cdr)

struct snow_symbol {
    SNOW_HEADER;

    snow_object       _value;
    snow_object       _fun;
    snow_object       _name;
};
#define SNOW_SYM_FUNC(_that_)       ((_that_)->_symbol._func)

struct snow_single_float {
    SNOW_HEADER;

    float _val;
};
#define SNOW_SINGLE_FLOAT(_that_)   ((_that_)->_sf._val)

struct snow_double_float {
    SNOW_HEADER;

    double _val;
};
#define SNOW_DOUBLE_FLOAT(_that_)   ((_that_)->_df._val)

#define SNOW_OBJTYPE(_that_)        ((_that_)->_type_id)
#define SNOW_NILP(_that_)           ((_that_) == SNOW_NIL)
#define SNOW_LISTP(_that_)          (SNOW_NILP(_that_) || (SNOW_OBJTYPE(_that_) == SNOW_CONS_TAG))
#define SNOW_CONSP(_that_)          (!SNOW_NILP(_that_) && (SNOW_OBJTYPE(_that_) == SNOW_CONS_TAG))
#define SNOW_SYMBOLP(_that_)        (SNOW_NILP(_that_) || (SNOW_OBJTYPE(_that_) == SNOW_SYMBOL_TAG))

union snow_object {
    struct snow_cons          _cons;
    struct snow_symbol        _symbol;
    struct snow_single_float  _sf;
    struct snow_double_float  _df;
};

#endif  /* object_h */
// Local Variables:
//   coding: utf-8
// End:
