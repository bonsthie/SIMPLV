#ifndef __SIMPL_H__
#define __SIMPL_H__

#include "multiarch/type_avx.h"
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

#ifndef __SIMPL_TYPE_ONLY

vec v32c_add(vec __a, vec __b);

vec v256b_set_char(char __a, char __b, char __c, char __d, char __e, char __f,
                   char __g, char __h, char __i, char __j, char __k, char __l,
                   char __m, char __n, char __o, char __p, char __q, char __r,
                   char __s, char __t, char __u, char __v, char __w, char __x,
                   char __y, char __z, char __aa, char __bb, char __cc,
                   char __dd, char __ee, char __ff);

vec v256b_set1_char(char __a);

#endif /* __SIMPL_TYPE_ONLY */

#endif /* __SIMPL_H__ */
