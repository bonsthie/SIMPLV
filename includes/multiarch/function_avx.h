#ifndef __FUNCTION_AVX_H__
#warning "Please include simpl.h instead of directly including function_avx.h"
#endif

#ifndef __FUNCTION_AVX_H__
#define __FUNCTION_AVX_H__

#include <simpl.h>

#ifndef __FORCE_INLINE
#define __FORCE_INLINE __attribute__((__always_inline__, __artificial__))
#endif

#ifndef _FUNC_AVX
#define _FUNC_AVX(x) __simpl_ ## x ## _avx
#endif

inline vec __FORCE_INLINE _FUNC_AVX(v32c_add)(vec __a, vec __b) {
  vec result;
  result.t_char.v256 = __a.t_char.v256 + __b.t_char.v256;
  return result;
}

inline vec __FORCE_INLINE _FUNC_AVX(v256b_set_char)(
    char __a, char __b, char __c, char __d, char __e, char __f, char __g,
    char __h, char __i, char __j, char __k, char __l, char __m, char __n,
    char __o, char __p, char __q, char __r, char __s, char __t, char __u,
    char __v, char __w, char __x, char __y, char __z, char __aa, char __bb,
    char __cc, char __dd, char __ee, char __ff) {
  vec result;

  result.t_char.v256 =
      (__v32c){__a, __b, __c, __d, __e,  __f,  __g,  __h,  __i,  __j, __k,
               __l, __m, __n, __o, __p,  __q,  __r,  __s,  __t,  __u, __v,
               __w, __x, __y, __z, __aa, __bb, __cc, __dd, __ee, __ff};

  return result;
}

inline vec __FORCE_INLINE _FUNC_AVX(v256b_set1_char)(char __a) {
  return (_FUNC_AVX(v256b_set_char)(__a, __a, __a, __a, __a, __a, __a, __a, __a,
                                   __a, __a, __a, __a, __a, __a, __a, __a, __a,
                                   __a, __a, __a, __a, __a, __a, __a, __a, __a,
                                   __a, __a, __a, __a, __a));
}

#endif /* __FUNCTION_AVX_H__ */
