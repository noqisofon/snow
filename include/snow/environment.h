/* 
     environment.h  -  environment structs and functions
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
#ifndef snow_environment_h
#define snow_environment_h

#include <snow/object.h>

SNOW_EXTERN_C_BEGIN

/*
 * We will represent the environment as a list of frames.
 * Each frame is an association list (alist) of bindings.
 * For now, let's keep it simple: just a single list of bindings (global scope only for now, or just implicit scoping).
 * Actually, to support function calls properly later, we need chaining.
 *
 * Let's define the struct snow_env_s to hold the current frame.
 */

struct snow_env_s {
    volatile int _disable_interrupts;
    SNObject_ref bindings; /* Association list: ((sym . val) (sym . val) ...) */
    struct snow_env_s* parent; /* Enclosing environment */
};

/* Function declarations */

/*
 * \brief Create a new empty environment.
 * \param parent The parent environment (NULL for top-level).
 */
SNOW_API SNEnvironment_ref snow_env_create(SNEnvironment_ref parent);

/*
 * \brief Bind a symbol to a value in the current environment frame.
 */
SNOW_API void snow_env_bind(SNEnvironment_ref env, SNObject_ref symbol, SNObject_ref value);

/*
 * \brief Lookup a symbol in the environment (searching parents).
 * \return The value bound to the symbol, or SNOW_NIL (or error indicator) if not found.
 */
SNOW_API SNObject_ref snow_env_lookup(SNEnvironment_ref env, SNObject_ref symbol);


SNOW_EXTERN_C_END


#endif  /* snow_environment_h */
// Local Variables:
//   coding: utf-8
// End:
