#ifndef snow_read_h
#define snow_read_h

#include <stdio.h>
#include <snow/snow.h>

SNOW_EXTERN_C_BEGIN

SNOW_API SNObject_ref snow_read( SNOW_ENV, FILE *stream );

SNOW_EXTERN_C_END

#endif
