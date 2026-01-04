/*
  \file _system.h
  \since 2014
  \brief 
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
#ifndef snow_config_system_h
#define snow_config_system_h

#if defined(__sun)

#elif defined(linux) || defined(__linux__)
#   define SNOW_PLATFORM   "Linux"
#   include <snow/config/_linux.h>
#   if defined(__GNUC__)
#       include <snow/config/_gcc.h>
#   endif  /* defined(__GNUC__) */

#elif defined(__CYGWIN__)
#   defined SNOW_PLATFORM   "Cygwin"
#   include <snow/config/_cygwin.h>
#   if defined(__GNUC__)
#       include <snow/config/_gcc.h>
#   endif  /* defined(__GNUC__) */

#elif defined(__MINGW32__)
#   if defined(__GNUC__)
#       include <snow/config/_gcc.h>
#   endif  /* defined(__GNUC__) */
#   include <snow/config/_windows.h>

#elif defined(_WIN32) || defined(__WIN32) || defined(WIN32) || defined(__WIN32__) || \
    defined(_WIN16) || defined(__WIN16) || defined(WIN16)

#   if defined(__BORLAND__)             /* Borland C++ */
#       include <snow/config/_bcc.h>
#   elif defined(_MSC_VER)
#       include <snow/config/_msvc.h>
#   endif

#else
#   error Unknown platform !!
#endif  /* defined(__sun) */

#endif  /* snow_config_system_h */
// Local Variable:
//   coding: utf-8
// End:
