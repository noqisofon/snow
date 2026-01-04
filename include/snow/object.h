/*!
 * \file object.h
 * \brief Lisp のデータ構造を表す構造体とそれに関係する関数やマクロ。
 * \author ned rihine
 * \date 2014
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
#    define snow_object_h

SNOW_EXTERN_C_BEGIN

/* Forward declarations for Environment to break circular dependency */
struct snow_env_s;
typedef struct snow_env_s *SNEnvironment_ref;

#    ifndef SNOW_ENV
#        define SNOW_ENV const SNEnvironment_ref env
#    endif

/*!
 * \typedef Snow_TypeID object.h
 * \brief snow の型 ID 用の列挙体。
 */
typedef enum snow_type_id {
    SNOW_TYPE_NIL       = 0,
    SNOW_TYPE_ATOM      = 1,
    SNOW_TYPE_CONS      = ( 1 << 1 ) | SNOW_TYPE_ATOM,
    SNOW_TYPE_CHARACTER = ( 1 << 2 ) | SNOW_TYPE_ATOM,
    SNOW_TYPE_NUMERIC   = ( 1 << 3 ) | SNOW_TYPE_ATOM,
    SNOW_TYPE_BOOLEAN   = ( 1 << 4 ) | SNOW_TYPE_ATOM,
    SNOW_TYPE_SYMBOL    = ( 1 << 5 ) | SNOW_TYPE_ATOM,
    SNOW_TYPE_BUILTIN   = ( 1 << 6 ) | SNOW_TYPE_ATOM,
} Snow_TypeID;

/*!
 * \struct snow_lisp_val_s object.h
 * \brief Lisp オブジェクトの先頭部分。
 *
 * snow_lisp_val_s 構造体は Lisp オブジェクトの先頭部分を表します。
 *
 */
struct snow_lisp_val_s;

/*!
 * \typedef SNObject_ref object.h
 * \brief オブジェクトへの参照型(ポインタ)。
 */
typedef struct snow_lisp_val_s *SNObject_ref;

/*!
 * \typedef SNAtom_ref object.h
 * \brief アトムへの参照型(ポインタ)。
 *
 */
typedef SNObject_ref            SNAtom_ref;

/*!
 * \typedef SNBuiltinFunc object.h
 * \brief Builtin function pointer type.
 */
typedef SNObject_ref            ( *SNBuiltinFunc )( SNOW_ENV, SNObject_ref args );

/*!
 * \def SNOW_STRUCT_HEADER
 * \brief Lisp 用のデータ構造を表す構造体の既定メンバーを宣言するマクロ。
 *
 *
 */
#    define SNOW_STRUCT_HEADER                                                                                         \
        uint8_t      type_id;                                                                                          \
        SNObject_ref base

struct snow_lisp_val_s {
    SNOW_STRUCT_HEADER;
};

/*!
 * \struct snow_cons_s object.h
 * \brief CONS セルを表す構造体。
 */
struct snow_cons_s {
    SNOW_STRUCT_HEADER;

    SNObject_ref car;
    SNObject_ref cdr;
};

/*!
 * \typedef SNCons_ref object.h
 * \brief Consへの参照型(ポインタ)。
 *
 */
typedef struct snow_cons_s *SNCons_ref;

/*!
 * \struct snow_symbol_s object.h
 * \brief Symbolを表す構造体。
 */
struct snow_symbol_s {
    SNOW_STRUCT_HEADER;
    char *name;
};

/*!
 * \struct snow_builtin_s object.h
 * \brief Builtin function object.
 */
struct snow_builtin_s {
    SNOW_STRUCT_HEADER;
    SNBuiltinFunc func;
    char         *name;
};

#    define SNOW_SET_TYPEID( obj, id ) ( ( obj )->type_id = ( id ) )
#    define SNOW_NIL                   NULL

/*!
 *
 */
SNOW_API SNObject_ref snow_make_cons( SNOW_ENV, SNObject_ref car, SNObject_ref cdr );

/*!
 *
 */
SNOW_API SNObject_ref snow_make_symbol( SNOW_ENV, const char *name );

/*!
 *
 */
SNOW_API SNObject_ref snow_make_builtin( SNOW_ENV, SNBuiltinFunc func, const char *name );

SNOW_EXTERN_C_END

#endif /* snow_object_h */
// Local Variables:
//   coding: utf-8
// End:
