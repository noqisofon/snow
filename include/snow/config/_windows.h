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

#endif  /* snow_config__window_h */
