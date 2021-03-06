/*
  \file snow.h
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
#ifndef snow_snow_h
#define snow_snow_h

#include <sys/types.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifndef TRUE
#   define   TRUE    1
#endif  /* ndef TRUE */

#ifndef FALSE
#   define   FALSE   0
#endif  /* ndef TRUE */

#ifndef __cplusplus
#   include <stdbool.h>
#endif  /* ndef __cplusplus */

#if defined(__cplusplus)
#   define SNOW_EXTERN_C_BEGIN    extern "C" {
#   define SNOW_EXTERN_C_END      }
#else
#   define SNOW_EXTERN_C_BEGIN
#   define SNOW_EXTERN_C_END
#endif  /* defined(__cplusplus) */

#include <snow/config/_system.h>

#include <snow/object.h>

#endif  /* snow_snow_h */
// Local Variables:
//   coding: utf-8
// End:
