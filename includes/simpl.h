#ifndef __SIMPL_H__
#define __SIMPL_H__

#include <sys/cdefs.h>
#define __WARNING_TYPE_AVX_H__
#include "multiarch/type_avx.h"
#define __WARNING_TYPE_SSE_H__
#include "multiarch/type_sse.h"

/* Aligned types (default) */

/* Normal type */
typedef union v4d {
  __v4d v256;
  __v2d v128[2];
} v4d;

typedef union v8f {
  __v8f v256;
  __v4f v128[2];
} v8f;

typedef union v4ll {
  __v4ll v256;
  __v2ll v128[2];
} v4ll;

typedef union v8i {
  __v8i v256;
  __v4i v128[2];
} v8i;

typedef union v16s {
  __v16s v256;
  __v8s v128[2];
} v16s;

typedef union v32c {
  __v32c v256;
  __v16c v128[2];
} v32c;

typedef union v32sc {
  __v32sc v256;
  __v16sc v128[2];
} v32sc;

/* Unaligned types */
typedef union v4ull {
  __v4ull v256;
  __v2ull v128[2];
} v4ull;

typedef union v8ui {
  __v8ui v256;
  __v4ui v128[2];
} v8ui;

typedef union v16us {
  __v16us v256;
  __v8us v128[2];
} v16us;

typedef union v32uc {
  __v32uc v256;
  __v16uc v128[2];
} v32uc;

/* Unaligned types */

/* Normal type */
typedef union uv4d {
  __uv4d uv256;
  __uv2d uv128[2];
} uv4d;

typedef union uv8f {
  __uv8f uv256;
  __uv4f uv128[2];
} uv8f;

typedef union uv4ll {
  __uv4ll uv256;
  __uv2ll uv128[2];
} uv4ll;

typedef union uv8i {
  __uv8i uv256;
  __uv4i uv128[2];
} uv8i;

typedef union uv16s {
  __uv16s uv256;
  __uv8s uv128[2];
} uv16s;

typedef union uv32c {
  __uv32c uv256;
  __uv16c uv128[2];
} uv32c;

typedef union uv32sc {
  __uv32sc uv256;
  __uv16sc uv128[2];
} uv32sc;

/* Unaligned types */
typedef union uv4ull {
  __uv4ull uv256;
  __uv2ull uv128[2];
} uv4ull;

typedef union uv8ui {
  __uv8ui uv256;
  __uv4ui uv128[2];
} uv8ui;

typedef union uv16us {
  __uv16us uv256;
  __uv8us uv128[2];
} uv16us;

typedef union uv32uc {
  __uv32uc uv256;
  __uv16uc uv128[2];
} uv32uc;

/* VEC definition */

typedef union vec {
  v4d t_double;
  v8f t_float;
  v4ll t_long_long;
  v8i t_int;
  v16s t_short;
  v32c t_char;
  v32sc t_signed_char;

  v4ull t_ulong_long;
  v8ui t_uint;
  v16us t_ushort;
  v32uc t_uchar;
} vec;

/* VEC unaligned definition */

typedef union uvec {
  uv4d t_double;
  uv8f t_float;
  uv4ll t_long_long;
  uv8i t_int;
  uv16s t_short;
  uv32c t_char;
  uv32sc t_signed_char;

  uv4ull t_ulong_long;
  uv8ui t_uint;
  uv16us t_ushort;
  uv32uc t_uchar;
} uvec;

#ifndef __SIMPL_TYPE_ONLY

#define __WARNING_FUNCTION_AVX_H__
#include "multiarch/function_avx.h"
#define __WARNING_FUNCTION_SSE_H__
#include "multiarch/function_sse.h"

#ifdef VERBOSE
#include <stdio.h>
#define IFUNC_LOG(func) printf("simpl ifunc %s is selected\n", #func);
#else
#define IFUNC_LOG(func)
#endif

#define _func_selected(func)                                                   \
  {                                                                            \
    IFUNC_LOG(func)                                                            \
    return func;                                                               \
  }

#if defined(__AVX2__)
#define __CASE_AVX(name, param_names)                                          \
  case 1:                                                                      \
    return (_FUNC_AVX(name) param_names);                                      \
    break;
#else
#define __CASE_AVX(name, param_names)
#endif

#define __CASE_SSE(name, param_names)                                          \
  default:                                                                     \
    return (_FUNC_SSE(name) param_names);                                      \
    break;

#define __DUMMY_CASE_FUNC_INIT(name, return_type, param_types)

#define simpl_func_init(name, index, return_type, param_types, param_names)    \
  extern inline                                                                \
      __attribute__((always_inline, __min_vector_width__(                      \
                                        128))) return_type name param_types {  \
    switch (index) {                                                           \
      __CASE_AVX(name, param_names)                                            \
      __CASE_SSE(name, param_names)                                            \
    }                                                                          \
  }

simpl_func_init(v32c_add, 1, vec, (vec __a, vec __b), (__a, __b));

simpl_func_init(v32c_cmpeq, 1, vec, (vec __a, vec __b), (__a, __b));

simpl_func_init(v256b_set_char, 1, vec,
                (char __a, char __b, char __c, char __d, char __e, char __f,
                 char __g, char __h, char __i, char __j, char __k, char __l,
                 char __m, char __n, char __o, char __p, char __q, char __r,
                 char __s, char __t, char __u, char __v, char __w, char __x,
                 char __y, char __z, char __aa, char __bb, char __cc, char __dd,
                 char __ee, char __ff),
                (__a, __b, __c, __d, __e, __f, __g, __h, __i, __j, __k, __l,
                 __m, __n, __o, __p, __q, __r, __s, __t, __u, __v, __w, __x,
                 __y, __z, __aa, __bb, __cc, __dd, __ee, __ff));

simpl_func_init(v256b_set1_char, 1, vec, (char __a), (__a));

simpl_func_init(v32c_movemask, 1, int, (vec __a), (__a));

simpl_func_init(v256b_loadu, 1, vec, (const uvec *__a), (__a));

#endif /* __SIMPL_TYPE_ONLY */

#endif /* __SIMPL_H__ */
