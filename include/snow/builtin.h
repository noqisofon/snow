/* 
     builtin.h  -  buildin functions
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
#ifndef snow_builtin_h
#define snow_builtin_h


_BEGIN_EXTERN_C


/*!
 *
 */
SNOW_API SNObject_ref snow_cons(SNOW_ENV, SNObject_ref car, SNObject_ref cdr);


_END_EXTERN_C


#endif  /* snow_builtin_h */
// Local Variables:
//   coding: utf-8
// End:
