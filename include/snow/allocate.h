/*!
   \file allocate.h
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
#ifndef snow_allocate_h
#define snow_allocate_h


_BEGIN_EXTERN_C


/*!
 *
 */
SNOW_API void* snow_malloc(SNOW_ENV, size_t size);


/*!
 *
 */
SNOW_API void* snow_atomic_malloc(SNOW_ENV, size_t size);


/*!
 *
 */
SNOW_API void snow_free(SNOW_ENV, void* memp);


_END_EXTERN_C


#endif  /* snow_allocate_h */
// Local Variables:
//   coding: utf-8
// End:
