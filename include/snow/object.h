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
#define snow_object_h

_BEGIN_EXTERN_C


/*!
 * \typedef Snow_TypeID object.h
 * \brief snow の型 ID 用の列挙体。
 */
typedef enum snow_type_id {
    kSnow_TypeID_NIL          = 0,
    kSnow_TypeID_ATOM         = 1,
    kSnow_TypeID_CONS         = (1 << 1) | Snow_TypeID_ATOM,
    kSnow_TypeID_CHARACTER    = (1 << 2) | Snow_TypeID_ATOM,
    kSnow_TypeID_NUMERIC      = (1 << 3) | Snow_TypeID_ATOM,
    kSnow_TypeID_BOOLEAN      = (1 << 4) | Snow_TypeID_ATOM,
} Snow_TypeID;


/*!
 * \def SNOW_STRUCT_HEADER
 * \brief Lisp 用のデータ構造を表す構造体の既定メンバーを宣言するマクロ。
 *
 * 
 */
#define SNOW_STRUCT_HEADER                      \
    uint8_t     type_id;                       \
    SNAtom_ref  base

/*!
 * \struct snow_lisp_val_s object.h
 * \brief Lisp オブジェクトの先頭部分。
 * 
 * snow_lisp_val_s 構造体は Lisp オブジェクトの先頭部分を表します。
 * 
 */
struct snow_lisp_val_s {
    SNOW_STRUCT_HEADER;
};

/*!
 * \typedef SNAtom_ref object.h
 * \brief アトムへの参照型(ポインタ)。
 * 
 */
typedef struct snow_lisp_val_s*   SNAtom_ref;


/*!
 * \struct snow_cons_s object.h
 * \brief CONS セルを表す構造体。
 */
struct snow_cons_s {
    SNOW_STRUCT_HEADER;

    SNAtom_ref   car;
    SNAtom_ref   cdr;
};

/*!
 * \typedef SNCons_ref object.h
 * \brief アトムへの参照型(ポインタ)。
 * 
 */
typedef struct snow_cons_s*  SNCons_ref;


/*!
 *
 */
SNOW_API SNCons_ref snow_make_cons(SNAtom_ref car, SNAtom_ref cdr);


_END_EXTERN_C

#endif  /* snow_object_h */
// Local Variables:
//   coding: utf-8
// End:
