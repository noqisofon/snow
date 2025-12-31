/*
  \file _gcc.h
  \brief GCC configuration.
*/
#ifndef snow_config__gcc_h
#define snow_config__gcc_h

#ifndef SNOW_COMPILER_NAME
#   define SNOW_COMPILER_NAME     "GCC"
#endif

#define    SNOW_EXPORT_DECLSPEC      __attribute__((visibility("default")))
#define    SNOW_IMPORT_DECLSPEC

#if defined(SNOW_BUILDING)
#   define   SNOW_DECLSPEC    SNOW_EXPORT_DECLSPEC
#else
#   define   SNOW_DECLSPEC    SNOW_IMPORT_DECLSPEC
#endif

#ifndef SNOW_EXTERN
#   ifdef __cplusplus
#       define SNOW_EXTERN extern
#   else
#       define SNOW_EXTERN
#   endif
#endif

#ifndef SNOW_API
#   define   SNOW_API         SNOW_EXTERN SNOW_DECLSPEC
#endif

#endif  /* snow_config__gcc_h */
