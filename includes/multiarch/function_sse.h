#ifndef __WARNING_FUNCTION_SSE_H__
#warning "Please include simpl.h instead of directly including function_sse.h"
#endif

#ifndef __FUNCTION_SSE_H__
#define __FUNCTION_SSE_H__

#define __SIMPLV_TYPE_ONLY
#include "../simpl.h"
#undef __SIMPLV_TYPE_ONLY

#ifndef __FUNC_ATTR_SSE
#define __FUNC_ATTR_SSE                                                        \
  __attribute__((__always_inline__, __nodebug__, __target__("sse"),            \
                 __min_vector_width__(128)))
#endif

#ifndef _FUNC_SSE
#define _FUNC_SSE(x) __simpl_##x##_sse
#endif

#define __BASIC_FUNC_SSE_128(name, type, sign)                                 \
  static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(name)(vec128 __a,             \
                                                       vec128 __b) {           \
    vec128 result;                                                             \
    result.type = __a.type sign __b.type;                                      \
    return result;                                                             \
  }

#define __BASIC_FUNC_SSE_256(name, type, sign)                                 \
  static inline vec __FUNC_ATTR_SSE _FUNC_SSE(name)(vec __a, vec __b) {        \
    vec result;                                                                \
    result.type.v128[0] = __a.type.v128[0] sign __b.type.v128[0];              \
    result.type.v128[1] = __a.type.v128[1] sign __b.type.v128[1];              \
    return result;                                                             \
  }

#define __BASIC_FUNC_SSE_128_ALL_TYPE(name, sign)                              \
  __BASIC_FUNC_SSE_128(v16c_##name, t_char, sign)                              \
  __BASIC_FUNC_SSE_128(v16sc_##name, t_schar, sign)                            \
  __BASIC_FUNC_SSE_128(v16uc_##name, t_uchar, sign)                            \
  __BASIC_FUNC_SSE_128(v8s_##name, t_short, sign)                              \
  __BASIC_FUNC_SSE_128(v8us_##name, t_ushort, sign)                            \
  __BASIC_FUNC_SSE_128(v4i_##name, t_int, sign)                                \
  __BASIC_FUNC_SSE_128(v4ui_##name, t_uint, sign)                              \
  __BASIC_FUNC_SSE_128(v4f_##name, t_float, sign)                              \
  __BASIC_FUNC_SSE_128(v2d_##name, t_double, sign)                             \
  __BASIC_FUNC_SSE_128(v2ll_##name, t_long_long, sign)                         \
  __BASIC_FUNC_SSE_128(v2ull_##name, t_ulong_long, sign)

#define __BASIC_FUNC_SSE_256_ALL_TYPE(name, sign)                              \
  __BASIC_FUNC_SSE_256(v32c_##name, t_char, sign)                              \
  __BASIC_FUNC_SSE_256(v32sc_##name, t_schar, sign)                            \
  __BASIC_FUNC_SSE_256(v32uc_##name, t_uchar, sign)                            \
  __BASIC_FUNC_SSE_256(v16s_##name, t_short, sign)                              \
  __BASIC_FUNC_SSE_256(v16us_##name, t_ushort, sign)                            \
  __BASIC_FUNC_SSE_256(v8i_##name, t_int, sign)                                \
  __BASIC_FUNC_SSE_256(v8ui_##name, t_uint, sign)                              \
  __BASIC_FUNC_SSE_256(v8f_##name, t_float, sign)                              \
  __BASIC_FUNC_SSE_256(v4d_##name, t_double, sign)                             \
  __BASIC_FUNC_SSE_256(v4ll_##name, t_long_long, sign)                         \
  __BASIC_FUNC_SSE_256(v4ull_##name, t_ulong_long, sign)

#define __BASIC_FUNC_SSE_ALL_TYPE(name, sign) \
	__BASIC_FUNC_SSE_128_ALL_TYPE(name, sign) \
	__BASIC_FUNC_SSE_256_ALL_TYPE(name, sign) \

__BASIC_FUNC_SSE_ALL_TYPE(add, +)
__BASIC_FUNC_SSE_ALL_TYPE(sub, -)
__BASIC_FUNC_SSE_ALL_TYPE(mul, *)
__BASIC_FUNC_SSE_ALL_TYPE(div, /)
__BASIC_FUNC_SSE_ALL_TYPE(cmpeq, ==)
__BASIC_FUNC_SSE_ALL_TYPE(cmpgt, >)
__BASIC_FUNC_SSE_ALL_TYPE(cmplt, <)
__BASIC_FUNC_SSE_ALL_TYPE(cmpge, >=)
__BASIC_FUNC_SSE_ALL_TYPE(cmple, <=)

#undef __FUNC_ATTR_SSE
#undef __SIMPLV_TYPE_ONLY

#endif /* __FUNCTION_SSE_H__ */
