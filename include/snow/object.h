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
#ifndef snow_object_h
#define snow_object_h


_BEGIN_EXTERN_C


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
    snow_t_stream       = ( 14 << 2 ) | snow_t_object,
} snow_type_id;


#define SNOW_HEADER             \
    uint8_t _type_id;           \
    SNObject_ref _base

#define SNOW_NIL                                ((SNObject_ref)NULL)

#define SNOW_TAG_BITS           2

#define SNOW_CHARACTER_TAG      snow_t_charater
#define SNOW_FIXNUM_TAG         snow_t_fixnum
#define SNOW_STRING_TAG         snow_t_string
#define SNOW_SYMBOL_TAG         snow_t_symbol

struct snow_generic_s {
    SNOW_HEADER;
};

#define SNOW_SET_TYPEID(_that_, _type_id_)      (((SNObject_ref)(_that_))->_type_id) = _type_id_
#define SNOW_OBJTYPE(_that_)                    (((SNObject_ref)(_that_))->_type_id)
#define SNOW_NILP(_that_)                       (((SNObject_ref)(_that_)) == SNOW_NIL)

struct snow_cons_s {
    SNOW_HEADER;

    SNObject_ref   _car;
    SNObject_ref   _cdr;
};

typedef struct snow_cons_s*  SNCons_ref;

#define SNOW_CONS_CAR(_that_)                   (((SNCons_ref)(_that_))->_car)
#define SNOW_CONS_CDR(_that_)                   (((SNCons_ref)(_that_))->_cdr)

#define SNOW_LISTP(_that_)                      ( SNOW_NILP(_that_) || (SNOW_OBJTYPE(_that_) == SNOW_CONS_TAG))
#define SNOW_CONSP(_that_)                      (!SNOW_NILP(_that_) && (SNOW_OBJTYPE(_that_) == SNOW_CONS_TAG))

/*!
 * 
 */
SNOW_API SNObject_ref snow_make_cons(SNOW_ENV);

struct snow_symbol_s {
    SNOW_HEADER;

    SNObject_ref       _value;
    SNObject_ref       _fun;
    SNObject_ref       _name;
};

typedef struct snow_symbol_s*  SNSymbol_ref;

#define SNOW_SYM_FUNC(_that_)                   (((SNSymbol_ref)(_that_))_func)

#define SNOW_SYMBOLP(_that_)                    (SNOW_NILP(_that_) || (SNOW_OBJTYPE(_that_) == SNOW_SYMBOL_TAG))

struct snow_single_float_s {
    SNOW_HEADER;

    float _val;
};

typedef struct snow_single_float_s*  SNSingleFloat_ref;

#define SNOW_SINGLE_FLOAT(_that_)               (((SNSingleFloat_ref)(_that_))->_val)

struct snow_double_float_s {
    SNOW_HEADER;

    double _val;
};

typedef struct snow_double_float_s* SNDoubleFloat_ref;

#define SNOW_DOUBLE_FLOAT(_that_)               (((SNDoubleFloat_ref)(_that_))->_val)


_END_EXTERN_C


#endif  /* snow_object_h */
// Local Variables:
//   coding: utf-8
// End:
