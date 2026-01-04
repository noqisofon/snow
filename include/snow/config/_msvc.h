/*
  \file _msvc.h
  \brief Microsoft Visual Studio C++ の設定。
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
#ifndef snow_config__msvc_h
#    define snow_config__msvc_h

#    ifndef SNOW_COMPILER_NAME
/*!
 * \def SNOW_COMPILER_NAME
 * コンパイラの名前を表します。
 */
#        define SNOW_COMPILER_NAME "Microsoft Visual Studio C++"
#    endif /* ndef SNOW_COMPILER_NAME */

/*!
 * \def SNOW_EXPORT_DECLSPEC
 * snow をビルドする際の __declspec を表します。
 */
#    define SNOW_EXPORT_DECLSPEC __declspec( dllexport )
/*!
 * \def SNOW_IMPORT_DECLSPEC
 * snow を使用する際の __declspec を表します。
 */
#    define SNOW_IMPORT_DECLSPEC __declspec( dllimport )

/*!
 * \def SNOW_DECLSPEC
 * \brief snow の __declspec を表します。
 *
 * Microsoft Visual Studio C++ では DLL をビルドする際に `__declspec(dllexport)` を遣い、
 * ビルドした DLL を使う際に `__declspec(dllimport)` を遣います。
 * このような「ルール」は非常にめんどくさいものです。
 * そこで、snow では \c SNOW_DECLSPEC にそのどちらかを定義しておくことにしました。
 */
#    if defined( SNOW_BUILDING )
#        define SNOW_DECLSPEC SNOW_EXPORT_DECLSPEC
#    else
#        define SNOW_DECLSPEC SNOW_IMPORT_DECLSPEC
#    endif /* defined(SNOW_BUILDING) */

#    ifndef SNOW_EXTERN
/*!
 * \def SNOW_EXTERN
 */
#        ifdef __cplusplus
#            define SNOW_EXTERN extern
#        else
#            define SNOW_EXTERN
#        endif /* def __cplusplus */
#    endif     /* ndef SNOW_EXTERN */

#    ifndef SNOW_API
/*!
 * \def SNOW_API
 *
 */
#        define SNOW_API SNOW_EXTERN SNOW_DECLSPEC
#    endif /* ndef SNOW_API */

#    if defined( __DLL ) || defined( _DLL ) || defined( _RTLDLL ) || defined( _AFXDLL )
/*!
 * \def SNOW_RUNTIME_DLL
 */
#        define SNOW_RUNTIME_DLL
#    endif /* defined(__DLL) || defined(_DLL) || defined(_RTLDLL) || defined(_AFXDLL) */

#    if defined( SNOW_BUILDING ) &&                                                                                    \
        ( defined( SNOW_USE_DYNAMIC_LIB ) || defined( SNOW_RUNTIME_DLL ) && !defined( SNOW_USE_STATIC_LIB ) )
#        define SNOW_DLL
#    endif /* defined(SNOW_BUILDING) && ( defined(SNOW_USE_DYNAMIC_LIB) || defined(SNOW_RUNTIME_DLL) &&                \
              !defined(SNOW_USE_STATIC_LIB) ) */

#endif /* snow_config__msvc_h */
// Local Variable:
//   coding: utf-8
// End:
