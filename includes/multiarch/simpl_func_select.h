#ifndef __SIMPLE_IFUNC_H__
#define __SIMPLE_IFUNC_H__

#include "function_avx.h"
#include "function_sse.h"

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

#define simpl_func_init(name, index, return_type, param_types, param_names)    \
  return_type(*name##_tab[2])                                                  \
      param_types = {_FUNC_SSE(name), _FUNC_AVX(name)};                        \
                                                                               \
  extern inline __attribute__((always_inline)) return_type name param_types {  \
    return name##_tab[index] param_names;                                      \
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

#endif
