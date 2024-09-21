#ifndef __SIMPLE_IFUNC_H__
#define __SIMPLE_IFUNC_H__

#include <multiarch/function_avx.h>
#include <multiarch/function_sse.h>
#include <simpl.h>

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

#define __FUNC_AVX(x) _FUNC_AVX(x)
#define __FUNC_SSE(x) _FUNC_SSE(x)

#define __simpl_ifunc_prototype(name, return_type, ...)                        \
  return_type __FUNC_SSE(name)(__VA_ARGS__);                                   \
  return_type __FUNC_AVX(name)(__VA_ARGS__);

#define __simpl_ifunc_creator(name, return_type, ...)                          \
  return_type (*name##_ifunc())(__VA_ARGS__) {                                 \
    if (1) {                                                                   \
      _func_selected(__FUNC_AVX(name));                                        \
    }                                                                          \
    if (1) {                                                                   \
      _func_selected(__FUNC_SSE(name));                                        \
    }                                                                          \
  }

#define simpl_ifunc_init(name, return_type, ...)                               \
  extern return_type name(__VA_ARGS__) __attribute__((ifunc(#name "_ifunc"))); \
  __simpl_ifunc_prototype(name, return_type, __VA_ARGS__)                      \
      __simpl_ifunc_creator(name, return_type, __VA_ARGS__)

#endif
