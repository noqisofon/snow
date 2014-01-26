/*
  \file _windows.h
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
#ifndef snow_config__window_h
#define snow_config__window_h

#ifndef SNOW_PLATFORM
#   defined SNOW_PLATFORM   "Windows"
#endif  /* ndef SNOW_PLATFORM */

#ifndef SNOW_WIN32_VERSION
#   if defined(_WINVER)
#       define    SNOW_WIN32_VERSION    _WINVER
#   elif defined(_WIN32_WINDOWS)
#       define    SNOW_WIN32_VERSION    _WIN32_WINDOWS
#   endif  /* defined(_WINVER) */
#endif  /* ndef SNOW_WIN32_VERSION */

#if !defined(SNOW_BIG_ENDIAN) && !defined(SNOW_LITTLE_ENDIAN)
#   if defined(_MIPSEB)
#       define  SNOW_BIG_ENDIAN        1
#   endif  /* defined(_MIPSEB) */

#   if defined(__i386) || defined(_M_IX86) || defined(_M_ARM) ||        \
    defined(__amd64__) || defined(_M_AMD64) || defined(__x86_64__) ||   \
    defined(__alpha__)
#       define    SNOW_LITTLE_ENDIAN     1
#   endif  /* defined(__i386)    || defined(_M_IX86)  || defined(_M_ARM)     ||   \
              defined(__amd64__) || defined(_M_AMD64) || defined(__x86_64__) ||   \
              defined(__alpha__) */

#   if defined(__ia64__)
#       if defined(__BIG_ENDIAN__)
#           define    SNOW_LITTLE_ENDIAN    1
#       else
#           define    SNOW_BIG_ENDIAN       1
#       endif  /* defined(__BIG_ENDIAN__) */
#   endif  /* defined(__ia64__) */

#endif  /* !defined(SNOW_BIG_ENDIAN) && !defined(SNOW_LITTLE_ENDIAN) */

#if !defined(SNOW_WINDOWS_H_INCLUDED)
#   define    SNOW_WINDOWS_H_INCLUDED

#   if !defined(SNOW_MSVC) || defined(__BORLANDC__) || defined(__ICL) || defined(__WATCOMC__) || \
    defined(__MINGW32__) || defined(__DMC__)
#       if defined(SNOW_USE_MFC)
#           include <afx.h>
#       else
#           include <windows.h>
#       endif  /* defined(SNOW_USE_MFC) */
#   else
SNOW_EXTERN_C_BEGIN



SNOW_EXTERN_C_END
#   endif  /* !defined(SNOW_MSVC)   || defined(__BORLANDC__) || defined(__ICL) || defined(__WATCOMC__) || \
               defined(__MINGW32__) || defined(__DMC__) */

#endif  /* !defined(SNOW_WINDOWS_H_INCLUDED) */

#endif  /* snow_config__window_h */
