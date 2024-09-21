#ifndef __FUNCTION_SSE_H__
#warning "Please include simpl.h instead of directly including function_sse.h"
#endif

#ifndef __FUNCTION_SSE_H__
#define __FUNCTION_SSE_H__

#include <simpl.h>

#ifndef __FORCE_INLINE
#define __FORCE_INLINE __attribute__((__always_inline__, __artificial__))
#endif

#ifndef _FUNC_SSE
#define _FUNC_SSE(x) __simpl_ ## x ## _sse
#endif

inline vec __FORCE_INLINE _FUNC_SSE(v32c_add)(vec __a, vec __b) {
  vec result;
  result.t_char.v128[0] = __a.t_char.v128[0] + __b.t_char.v128[0];
  result.t_char.v128[1] = __a.t_char.v128[1] + __b.t_char.v128[1];
  return result;
}

inline vec __FORCE_INLINE _FUNC_SSE(v256b_set_char)(
    char __a, char __b, char __c, char __d, char __e, char __f, char __g,
    char __h, char __i, char __j, char __k, char __l, char __m, char __n,
    char __o, char __p, char __q, char __r, char __s, char __t, char __u,
    char __v, char __w, char __x, char __y, char __z, char __aa, char __bb,
    char __cc, char __dd, char __ee, char __ff) {
  vec result;

  result.t_char.v128[0] = (__v16c){__a, __b, __c, __d, __e, __f, __g, __h,
                                   __i, __j, __k, __l, __m, __n, __o, __p};
  result.t_char.v128[1] = (__v16c){__q, __r, __s,  __t,  __u,  __v,  __w,  
								   __x, __y, __z, __aa, __bb, __cc, __dd,
								   __ee, __ff};
  return result;
}

inline vec __FORCE_INLINE _FUNC_SSE(v256b_set1_char)(char __a) {
  return (_FUNC_SSE(v256b_set_char)(__a, __a, __a, __a, __a, __a, __a, __a, __a,
                                    __a, __a, __a, __a, __a, __a, __a, __a, __a,
                                    __a, __a, __a, __a, __a, __a, __a, __a, __a,
                                    __a, __a, __a, __a, __a));
}

#endif /* __FUNCTION_SSE_H__ */
