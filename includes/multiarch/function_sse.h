#ifndef __WARNING_FUNCTION_SSE_H__
#warning "Please include simpl.h instead of directly including function_sse.h"
#endif

#ifndef __FUNCTION_SSE_H__
#define __FUNCTION_SSE_H__

#define __SIMPL_TYPE_ONLY
#include "../simpl.h"
#undef __SIMPL_TYPE_ONLY

#ifndef __FUNC_ATTR_SSE
#define __FUNC_ATTR_SSE                                                        \
  __attribute__((__always_inline__, __nodebug__, __target__("sse"),            \
                 __min_vector_width__(128)))
#endif

#ifndef _FUNC_SSE
#define _FUNC_SSE(x) __simpl_##x##_sse
#endif

/* ----------------start of header ----------- */

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32c_add)(vec __a, vec __b) {
  vec result;
  result.t_char.v128[0] = __a.t_char.v128[0] + __b.t_char.v128[0];
  result.t_char.v128[1] = __a.t_char.v128[1] + __b.t_char.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16c_add)(vec128 __a, vec128 __b) {
	vec128 result;
	result.t_char = __a.t_char + __b.t_char;
	return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32sc_add)(vec __a, vec __b) {
	vec result;
	result.t_schar.v128[0] = __a.t_schar.v128[0] + __b.t_schar.v128[0];
	result.t_schar.v128[1] = __a.t_schar.v128[1] + __b.t_schar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16sc_add)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_schar = __a.t_schar + __b.t_schar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32uc_add)(vec __a, vec __b) {
	vec result;
	result.t_uchar.v128[0] = __a.t_uchar.v128[0] + __b.t_uchar.v128[0];
	result.t_uchar.v128[1] = __a.t_uchar.v128[1] + __b.t_uchar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16uc_add)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uchar = __a.t_uchar + __b.t_uchar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16s_add)(vec __a, vec __b) {
  vec result;
  result.t_short.v128[0] = __a.t_short.v128[0] + __b.t_short.v128[0];
  result.t_short.v128[1] = __a.t_short.v128[1] + __b.t_short.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8s_add)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_short = __a.t_short + __b.t_short;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16us_add)(vec __a, vec __b) {
  vec result;
  result.t_ushort.v128[0] = __a.t_ushort.v128[0] + __b.t_ushort.v128[0];
  result.t_ushort.v128[1] = __a.t_ushort.v128[1] + __b.t_ushort.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8us_add)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ushort = __a.t_ushort + __b.t_ushort;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8i_add)(vec __a, vec __b) {
  vec result;
  result.t_int.v128[0] = __a.t_int.v128[0] + __b.t_int.v128[0];
  result.t_int.v128[1] = __a.t_int.v128[1] + __b.t_int.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4i_add)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_int = __a.t_int + __b.t_int;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8ui_add)(vec __a, vec __b) {
  vec result;
  result.t_uint.v128[0] = __a.t_uint.v128[0] + __b.t_uint.v128[0];
  result.t_uint.v128[1] = __a.t_uint.v128[1] + __b.t_uint.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4ui_add)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uint = __a.t_uint + __b.t_uint;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8f_add)(vec __a, vec __b) {
  vec result;
  result.t_float.v128[0] = __a.t_float.v128[0] + __b.t_float.v128[0];
  result.t_float.v128[1] = __a.t_float.v128[1] + __b.t_float.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4f_add)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_float = __a.t_float + __b.t_float;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4d_add)(vec __a, vec __b) {
  vec result;
  result.t_double.v128[0] = __a.t_double.v128[0] + __b.t_double.v128[0];
  result.t_double.v128[1] = __a.t_double.v128[1] + __b.t_double.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2d_add)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_double = __a.t_double + __b.t_double;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ll_add)(vec __a, vec __b) {
  vec result;
  result.t_long_long.v128[0] = __a.t_long_long.v128[0] + __b.t_long_long.v128[0];
  result.t_long_long.v128[1] = __a.t_long_long.v128[1] + __b.t_long_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ll_add)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_long_long = __a.t_long_long + __b.t_long_long;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ull_add)(vec __a, vec __b) {
  vec result;
  result.t_ulong_long.v128[0] = __a.t_ulong_long.v128[0] + __b.t_ulong_long.v128[0];
  result.t_ulong_long.v128[1] = __a.t_ulong_long.v128[1] + __b.t_ulong_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ull_add)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ulong_long = __a.t_ulong_long + __b.t_ulong_long;
  return result;
}


/* ----------------end of header ----------- */

/* ----------------start of header ----------- */

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32c_sub)(vec __a, vec __b) {
  vec result;
  result.t_char.v128[0] = __a.t_char.v128[0] - __b.t_char.v128[0];
  result.t_char.v128[1] = __a.t_char.v128[1] - __b.t_char.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16c_sub)(vec128 __a, vec128 __b) {
	vec128 result;
	result.t_char = __a.t_char - __b.t_char;
	return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32sc_sub)(vec __a, vec __b) {
	vec result;
	result.t_schar.v128[0] = __a.t_schar.v128[0] - __b.t_schar.v128[0];
	result.t_schar.v128[1] = __a.t_schar.v128[1] - __b.t_schar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16sc_sub)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_schar = __a.t_schar - __b.t_schar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32uc_sub)(vec __a, vec __b) {
	vec result;
	result.t_uchar.v128[0] = __a.t_uchar.v128[0] - __b.t_uchar.v128[0];
	result.t_uchar.v128[1] = __a.t_uchar.v128[1] - __b.t_uchar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16uc_sub)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uchar = __a.t_uchar - __b.t_uchar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16s_sub)(vec __a, vec __b) {
  vec result;
  result.t_short.v128[0] = __a.t_short.v128[0] - __b.t_short.v128[0];
  result.t_short.v128[1] = __a.t_short.v128[1] - __b.t_short.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8s_sub)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_short = __a.t_short - __b.t_short;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16us_sub)(vec __a, vec __b) {
  vec result;
  result.t_ushort.v128[0] = __a.t_ushort.v128[0] - __b.t_ushort.v128[0];
  result.t_ushort.v128[1] = __a.t_ushort.v128[1] - __b.t_ushort.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8us_sub)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ushort = __a.t_ushort - __b.t_ushort;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8i_sub)(vec __a, vec __b) {
  vec result;
  result.t_int.v128[0] = __a.t_int.v128[0] - __b.t_int.v128[0];
  result.t_int.v128[1] = __a.t_int.v128[1] - __b.t_int.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4i_sub)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_int = __a.t_int - __b.t_int;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8ui_sub)(vec __a, vec __b) {
  vec result;
  result.t_uint.v128[0] = __a.t_uint.v128[0] - __b.t_uint.v128[0];
  result.t_uint.v128[1] = __a.t_uint.v128[1] - __b.t_uint.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4ui_sub)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uint = __a.t_uint - __b.t_uint;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8f_sub)(vec __a, vec __b) {
  vec result;
  result.t_float.v128[0] = __a.t_float.v128[0] - __b.t_float.v128[0];
  result.t_float.v128[1] = __a.t_float.v128[1] - __b.t_float.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4f_sub)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_float = __a.t_float - __b.t_float;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4d_sub)(vec __a, vec __b) {
  vec result;
  result.t_double.v128[0] = __a.t_double.v128[0] - __b.t_double.v128[0];
  result.t_double.v128[1] = __a.t_double.v128[1] - __b.t_double.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2d_sub)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_double = __a.t_double - __b.t_double;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ll_sub)(vec __a, vec __b) {
  vec result;
  result.t_long_long.v128[0] = __a.t_long_long.v128[0] - __b.t_long_long.v128[0];
  result.t_long_long.v128[1] = __a.t_long_long.v128[1] - __b.t_long_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ll_sub)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_long_long = __a.t_long_long - __b.t_long_long;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ull_sub)(vec __a, vec __b) {
  vec result;
  result.t_ulong_long.v128[0] = __a.t_ulong_long.v128[0] - __b.t_ulong_long.v128[0];
  result.t_ulong_long.v128[1] = __a.t_ulong_long.v128[1] - __b.t_ulong_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ull_sub)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ulong_long = __a.t_ulong_long - __b.t_ulong_long;
  return result;
}

/* ----------------end of header ----------- */

/* *---------------start of header ----------- */

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32c_mul)(vec __a, vec __b) {
  vec result;
  result.t_char.v128[0] = __a.t_char.v128[0] * __b.t_char.v128[0];
  result.t_char.v128[1] = __a.t_char.v128[1] * __b.t_char.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16c_mul)(vec128 __a, vec128 __b) {
	vec128 result;
	result.t_char = __a.t_char * __b.t_char;
	return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32sc_mul)(vec __a, vec __b) {
	vec result;
	result.t_schar.v128[0] = __a.t_schar.v128[0] * __b.t_schar.v128[0];
	result.t_schar.v128[1] = __a.t_schar.v128[1] * __b.t_schar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16sc_mul)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_schar = __a.t_schar * __b.t_schar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32uc_mul)(vec __a, vec __b) {
	vec result;
	result.t_uchar.v128[0] = __a.t_uchar.v128[0] * __b.t_uchar.v128[0];
	result.t_uchar.v128[1] = __a.t_uchar.v128[1] * __b.t_uchar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16uc_mul)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uchar = __a.t_uchar * __b.t_uchar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16s_mul)(vec __a, vec __b) {
  vec result;
  result.t_short.v128[0] = __a.t_short.v128[0] * __b.t_short.v128[0];
  result.t_short.v128[1] = __a.t_short.v128[1] * __b.t_short.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8s_mul)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_short = __a.t_short * __b.t_short;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16us_mul)(vec __a, vec __b) {
  vec result;
  result.t_ushort.v128[0] = __a.t_ushort.v128[0] * __b.t_ushort.v128[0];
  result.t_ushort.v128[1] = __a.t_ushort.v128[1] * __b.t_ushort.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8us_mul)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ushort = __a.t_ushort * __b.t_ushort;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8i_mul)(vec __a, vec __b) {
  vec result;
  result.t_int.v128[0] = __a.t_int.v128[0] * __b.t_int.v128[0];
  result.t_int.v128[1] = __a.t_int.v128[1] * __b.t_int.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4i_mul)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_int = __a.t_int * __b.t_int;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8ui_mul)(vec __a, vec __b) {
  vec result;
  result.t_uint.v128[0] = __a.t_uint.v128[0] * __b.t_uint.v128[0];
  result.t_uint.v128[1] = __a.t_uint.v128[1] * __b.t_uint.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4ui_mul)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uint = __a.t_uint * __b.t_uint;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8f_mul)(vec __a, vec __b) {
  vec result;
  result.t_float.v128[0] = __a.t_float.v128[0] * __b.t_float.v128[0];
  result.t_float.v128[1] = __a.t_float.v128[1] * __b.t_float.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4f_mul)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_float = __a.t_float * __b.t_float;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4d_mul)(vec __a, vec __b) {
  vec result;
  result.t_double.v128[0] = __a.t_double.v128[0] * __b.t_double.v128[0];
  result.t_double.v128[1] = __a.t_double.v128[1] * __b.t_double.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2d_mul)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_double = __a.t_double * __b.t_double;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ll_mul)(vec __a, vec __b) {
  vec result;
  result.t_long_long.v128[0] = __a.t_long_long.v128[0] * __b.t_long_long.v128[0];
  result.t_long_long.v128[1] = __a.t_long_long.v128[1] * __b.t_long_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ll_mul)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_long_long = __a.t_long_long * __b.t_long_long;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ull_mul)(vec __a, vec __b) {
  vec result;
  result.t_ulong_long.v128[0] = __a.t_ulong_long.v128[0] * __b.t_ulong_long.v128[0];
  result.t_ulong_long.v128[1] = __a.t_ulong_long.v128[1] * __b.t_ulong_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ull_mul)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ulong_long = __a.t_ulong_long * __b.t_ulong_long;
  return result;
}

/* *---------------end of header ----------- */

// /---------------start of header ----------- //

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32c_div)(vec __a, vec __b) {
  vec result;
  result.t_char.v128[0] = __a.t_char.v128[0] / __b.t_char.v128[0];
  result.t_char.v128[1] = __a.t_char.v128[1] / __b.t_char.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16c_div)(vec128 __a, vec128 __b) {
	vec128 result;
	result.t_char = __a.t_char / __b.t_char;
	return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32sc_div)(vec __a, vec __b) {
	vec result;
	result.t_schar.v128[0] = __a.t_schar.v128[0] / __b.t_schar.v128[0];
	result.t_schar.v128[1] = __a.t_schar.v128[1] / __b.t_schar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16sc_div)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_schar = __a.t_schar / __b.t_schar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32uc_div)(vec __a, vec __b) {
	vec result;
	result.t_uchar.v128[0] = __a.t_uchar.v128[0] / __b.t_uchar.v128[0];
	result.t_uchar.v128[1] = __a.t_uchar.v128[1] / __b.t_uchar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16uc_div)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uchar = __a.t_uchar / __b.t_uchar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16s_div)(vec __a, vec __b) {
  vec result;
  result.t_short.v128[0] = __a.t_short.v128[0] / __b.t_short.v128[0];
  result.t_short.v128[1] = __a.t_short.v128[1] / __b.t_short.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8s_div)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_short = __a.t_short / __b.t_short;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16us_div)(vec __a, vec __b) {
  vec result;
  result.t_ushort.v128[0] = __a.t_ushort.v128[0] / __b.t_ushort.v128[0];
  result.t_ushort.v128[1] = __a.t_ushort.v128[1] / __b.t_ushort.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8us_div)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ushort = __a.t_ushort / __b.t_ushort;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8i_div)(vec __a, vec __b) {
  vec result;
  result.t_int.v128[0] = __a.t_int.v128[0] / __b.t_int.v128[0];
  result.t_int.v128[1] = __a.t_int.v128[1] / __b.t_int.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4i_div)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_int = __a.t_int / __b.t_int;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8ui_div)(vec __a, vec __b) {
  vec result;
  result.t_uint.v128[0] = __a.t_uint.v128[0] / __b.t_uint.v128[0];
  result.t_uint.v128[1] = __a.t_uint.v128[1] / __b.t_uint.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4ui_div)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uint = __a.t_uint / __b.t_uint;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8f_div)(vec __a, vec __b) {
  vec result;
  result.t_float.v128[0] = __a.t_float.v128[0] / __b.t_float.v128[0];
  result.t_float.v128[1] = __a.t_float.v128[1] / __b.t_float.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4f_div)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_float = __a.t_float / __b.t_float;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4d_div)(vec __a, vec __b) {
  vec result;
  result.t_double.v128[0] = __a.t_double.v128[0] / __b.t_double.v128[0];
  result.t_double.v128[1] = __a.t_double.v128[1] / __b.t_double.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2d_div)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_double = __a.t_double / __b.t_double;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ll_div)(vec __a, vec __b) {
  vec result;
  result.t_long_long.v128[0] = __a.t_long_long.v128[0] / __b.t_long_long.v128[0];
  result.t_long_long.v128[1] = __a.t_long_long.v128[1] / __b.t_long_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ll_div)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_long_long = __a.t_long_long / __b.t_long_long;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ull_div)(vec __a, vec __b) {
  vec result;
  result.t_ulong_long.v128[0] = __a.t_ulong_long.v128[0] / __b.t_ulong_long.v128[0];
  result.t_ulong_long.v128[1] = __a.t_ulong_long.v128[1] / __b.t_ulong_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ull_div)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ulong_long = __a.t_ulong_long / __b.t_ulong_long;
  return result;
}

// /---------------end of header ----------- //

// /---------------start of header ----------- //

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32c_cmpeq)(vec __a, vec __b) {
  vec result;
  result.t_char.v128[0] = __a.t_char.v128[0] == __b.t_char.v128[0];
  result.t_char.v128[1] = __a.t_char.v128[1] == __b.t_char.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16c_cmpeq)(vec128 __a, vec128 __b) {
	vec128 result;
	result.t_char = __a.t_char == __b.t_char;
	return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32sc_cmpeq)(vec __a, vec __b) {
	vec result;
	result.t_schar.v128[0] = __a.t_schar.v128[0] == __b.t_schar.v128[0];
	result.t_schar.v128[1] = __a.t_schar.v128[1] == __b.t_schar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16sc_cmpeq)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_schar = __a.t_schar == __b.t_schar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32uc_cmpeq)(vec __a, vec __b) {
	vec result;
	result.t_uchar.v128[0] = __a.t_uchar.v128[0] == __b.t_uchar.v128[0];
	result.t_uchar.v128[1] = __a.t_uchar.v128[1] == __b.t_uchar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16uc_cmpeq)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uchar = __a.t_uchar == __b.t_uchar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16s_cmpeq)(vec __a, vec __b) {
  vec result;
  result.t_short.v128[0] = __a.t_short.v128[0] == __b.t_short.v128[0];
  result.t_short.v128[1] = __a.t_short.v128[1] == __b.t_short.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8s_cmpeq)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_short = __a.t_short == __b.t_short;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16us_cmpeq)(vec __a, vec __b) {
  vec result;
  result.t_ushort.v128[0] = __a.t_ushort.v128[0] == __b.t_ushort.v128[0];
  result.t_ushort.v128[1] = __a.t_ushort.v128[1] == __b.t_ushort.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8us_cmpeq)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ushort = __a.t_ushort == __b.t_ushort;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8i_cmpeq)(vec __a, vec __b) {
  vec result;
  result.t_int.v128[0] = __a.t_int.v128[0] == __b.t_int.v128[0];
  result.t_int.v128[1] = __a.t_int.v128[1] == __b.t_int.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4i_cmpeq)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_int = __a.t_int == __b.t_int;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8ui_cmpeq)(vec __a, vec __b) {
  vec result;
  result.t_uint.v128[0] = __a.t_uint.v128[0] == __b.t_uint.v128[0];
  result.t_uint.v128[1] = __a.t_uint.v128[1] == __b.t_uint.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4ui_cmpeq)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uint = __a.t_uint == __b.t_uint;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8f_cmpeq)(vec __a, vec __b) {
  vec result;
  result.t_float.v128[0] = __a.t_float.v128[0] == __b.t_float.v128[0];
  result.t_float.v128[1] = __a.t_float.v128[1] == __b.t_float.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4f_cmpeq)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_float = __a.t_float == __b.t_float;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4d_cmpeq)(vec __a, vec __b) {
  vec result;
  result.t_double.v128[0] = __a.t_double.v128[0] == __b.t_double.v128[0];
  result.t_double.v128[1] = __a.t_double.v128[1] == __b.t_double.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2d_cmpeq)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_double = __a.t_double == __b.t_double;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ll_cmpeq)(vec __a, vec __b) {
  vec result;
  result.t_long_long.v128[0] = __a.t_long_long.v128[0] == __b.t_long_long.v128[0];
  result.t_long_long.v128[1] = __a.t_long_long.v128[1] == __b.t_long_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ll_cmpeq)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_long_long = __a.t_long_long == __b.t_long_long;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ull_cmpeq)(vec __a, vec __b) {
  vec result;
  result.t_ulong_long.v128[0] = __a.t_ulong_long.v128[0] == __b.t_ulong_long.v128[0];
  result.t_ulong_long.v128[1] = __a.t_ulong_long.v128[1] == __b.t_ulong_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ull_cmpeq)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ulong_long = __a.t_ulong_long == __b.t_ulong_long;
  return result;
}

/* -------- end header ------ */

// /---------------start of header ----------- //

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32c_cmpge)(vec __a, vec __b) {
  vec result;
  result.t_char.v128[0] = __a.t_char.v128[0] >= __b.t_char.v128[0];
  result.t_char.v128[1] = __a.t_char.v128[1] >= __b.t_char.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16c_cmpge)(vec128 __a, vec128 __b) {
	vec128 result;
	result.t_char = __a.t_char >= __b.t_char;
	return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32sc_cmpge)(vec __a, vec __b) {
	vec result;
	result.t_schar.v128[0] = __a.t_schar.v128[0] >= __b.t_schar.v128[0];
	result.t_schar.v128[1] = __a.t_schar.v128[1] >= __b.t_schar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16sc_cmpge)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_schar = __a.t_schar >= __b.t_schar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32uc_cmpge)(vec __a, vec __b) {
	vec result;
	result.t_uchar.v128[0] = __a.t_uchar.v128[0] >= __b.t_uchar.v128[0];
	result.t_uchar.v128[1] = __a.t_uchar.v128[1] >= __b.t_uchar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16uc_cmpge)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uchar = __a.t_uchar >= __b.t_uchar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16s_cmpge)(vec __a, vec __b) {
  vec result;
  result.t_short.v128[0] = __a.t_short.v128[0] >= __b.t_short.v128[0];
  result.t_short.v128[1] = __a.t_short.v128[1] >= __b.t_short.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8s_cmpge)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_short = __a.t_short >= __b.t_short;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16us_cmpge)(vec __a, vec __b) {
  vec result;
  result.t_ushort.v128[0] = __a.t_ushort.v128[0] >= __b.t_ushort.v128[0];
  result.t_ushort.v128[1] = __a.t_ushort.v128[1] >= __b.t_ushort.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8us_cmpge)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ushort = __a.t_ushort >= __b.t_ushort;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8i_cmpge)(vec __a, vec __b) {
  vec result;
  result.t_int.v128[0] = __a.t_int.v128[0] >= __b.t_int.v128[0];
  result.t_int.v128[1] = __a.t_int.v128[1] >= __b.t_int.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4i_cmpge)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_int = __a.t_int >= __b.t_int;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8ui_cmpge)(vec __a, vec __b) {
  vec result;
  result.t_uint.v128[0] = __a.t_uint.v128[0] >= __b.t_uint.v128[0];
  result.t_uint.v128[1] = __a.t_uint.v128[1] >= __b.t_uint.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4ui_cmpge)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uint = __a.t_uint >= __b.t_uint;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8f_cmpge)(vec __a, vec __b) {
  vec result;
  result.t_float.v128[0] = __a.t_float.v128[0] >= __b.t_float.v128[0];
  result.t_float.v128[1] = __a.t_float.v128[1] >= __b.t_float.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4f_cmpge)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_float = __a.t_float >= __b.t_float;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4d_cmpge)(vec __a, vec __b) {
  vec result;
  result.t_double.v128[0] = __a.t_double.v128[0] >= __b.t_double.v128[0];
  result.t_double.v128[1] = __a.t_double.v128[1] >= __b.t_double.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2d_cmpge)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_double = __a.t_double >= __b.t_double;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ll_cmpge)(vec __a, vec __b) {
  vec result;
  result.t_long_long.v128[0] = __a.t_long_long.v128[0] >= __b.t_long_long.v128[0];
  result.t_long_long.v128[1] = __a.t_long_long.v128[1] >= __b.t_long_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ll_cmpge)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_long_long = __a.t_long_long >= __b.t_long_long;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ull_cmpge)(vec __a, vec __b) {
  vec result;
  result.t_ulong_long.v128[0] = __a.t_ulong_long.v128[0] >= __b.t_ulong_long.v128[0];
  result.t_ulong_long.v128[1] = __a.t_ulong_long.v128[1] >= __b.t_ulong_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ull_cmpge)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ulong_long = __a.t_ulong_long >= __b.t_ulong_long;
  return result;
}

/* -------- end header ------ */

// /---------------start of header ----------- //

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32c_cmple)(vec __a, vec __b) {
  vec result;
  result.t_char.v128[0] = __a.t_char.v128[0] <= __b.t_char.v128[0];
  result.t_char.v128[1] = __a.t_char.v128[1] <= __b.t_char.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16c_cmple)(vec128 __a, vec128 __b) {
	vec128 result;
	result.t_char = __a.t_char <= __b.t_char;
	return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32sc_cmple)(vec __a, vec __b) {
	vec result;
	result.t_schar.v128[0] = __a.t_schar.v128[0] <= __b.t_schar.v128[0];
	result.t_schar.v128[1] = __a.t_schar.v128[1] <= __b.t_schar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16sc_cmple)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_schar = __a.t_schar <= __b.t_schar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32uc_cmple)(vec __a, vec __b) {
	vec result;
	result.t_uchar.v128[0] = __a.t_uchar.v128[0] <= __b.t_uchar.v128[0];
	result.t_uchar.v128[1] = __a.t_uchar.v128[1] <= __b.t_uchar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16uc_cmple)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uchar = __a.t_uchar <= __b.t_uchar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16s_cmple)(vec __a, vec __b) {
  vec result;
  result.t_short.v128[0] = __a.t_short.v128[0] <= __b.t_short.v128[0];
  result.t_short.v128[1] = __a.t_short.v128[1] <= __b.t_short.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8s_cmple)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_short = __a.t_short <= __b.t_short;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16us_cmple)(vec __a, vec __b) {
  vec result;
  result.t_ushort.v128[0] = __a.t_ushort.v128[0] <= __b.t_ushort.v128[0];
  result.t_ushort.v128[1] = __a.t_ushort.v128[1] <= __b.t_ushort.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8us_cmple)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ushort = __a.t_ushort <= __b.t_ushort;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8i_cmple)(vec __a, vec __b) {
  vec result;
  result.t_int.v128[0] = __a.t_int.v128[0] <= __b.t_int.v128[0];
  result.t_int.v128[1] = __a.t_int.v128[1] <= __b.t_int.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4i_cmple)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_int = __a.t_int <= __b.t_int;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8ui_cmple)(vec __a, vec __b) {
  vec result;
  result.t_uint.v128[0] = __a.t_uint.v128[0] <= __b.t_uint.v128[0];
  result.t_uint.v128[1] = __a.t_uint.v128[1] <= __b.t_uint.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4ui_cmple)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uint = __a.t_uint <= __b.t_uint;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8f_cmple)(vec __a, vec __b) {
  vec result;
  result.t_float.v128[0] = __a.t_float.v128[0] <= __b.t_float.v128[0];
  result.t_float.v128[1] = __a.t_float.v128[1] <= __b.t_float.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4f_cmple)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_float = __a.t_float <= __b.t_float;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4d_cmple)(vec __a, vec __b) {
  vec result;
  result.t_double.v128[0] = __a.t_double.v128[0] <= __b.t_double.v128[0];
  result.t_double.v128[1] = __a.t_double.v128[1] <= __b.t_double.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2d_cmple)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_double = __a.t_double <= __b.t_double;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ll_cmple)(vec __a, vec __b) {
  vec result;
  result.t_long_long.v128[0] = __a.t_long_long.v128[0] <= __b.t_long_long.v128[0];
  result.t_long_long.v128[1] = __a.t_long_long.v128[1] <= __b.t_long_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ll_cmple)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_long_long = __a.t_long_long <= __b.t_long_long;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ull_cmple)(vec __a, vec __b) {
  vec result;
  result.t_ulong_long.v128[0] = __a.t_ulong_long.v128[0] <= __b.t_ulong_long.v128[0];
  result.t_ulong_long.v128[1] = __a.t_ulong_long.v128[1] <= __b.t_ulong_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ull_cmple)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ulong_long = __a.t_ulong_long <= __b.t_ulong_long;
  return result;
}

/* -------- end header ------ */

// /---------------start of header ----------- //

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32c_cmpgt)(vec __a, vec __b) {
  vec result;
  result.t_char.v128[0] = __a.t_char.v128[0] > __b.t_char.v128[0];
  result.t_char.v128[1] = __a.t_char.v128[1] > __b.t_char.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16c_cmpgt)(vec128 __a, vec128 __b) {
	vec128 result;
	result.t_char = __a.t_char > __b.t_char;
	return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32sc_cmpgt)(vec __a, vec __b) {
	vec result;
	result.t_schar.v128[0] = __a.t_schar.v128[0] > __b.t_schar.v128[0];
	result.t_schar.v128[1] = __a.t_schar.v128[1] > __b.t_schar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16sc_cmpgt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_schar = __a.t_schar > __b.t_schar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32uc_cmpgt)(vec __a, vec __b) {
	vec result;
	result.t_uchar.v128[0] = __a.t_uchar.v128[0] > __b.t_uchar.v128[0];
	result.t_uchar.v128[1] = __a.t_uchar.v128[1] > __b.t_uchar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16uc_cmpgt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uchar = __a.t_uchar > __b.t_uchar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16s_cmpgt)(vec __a, vec __b) {
  vec result;
  result.t_short.v128[0] = __a.t_short.v128[0] > __b.t_short.v128[0];
  result.t_short.v128[1] = __a.t_short.v128[1] > __b.t_short.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8s_cmpgt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_short = __a.t_short > __b.t_short;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16us_cmpgt)(vec __a, vec __b) {
  vec result;
  result.t_ushort.v128[0] = __a.t_ushort.v128[0] > __b.t_ushort.v128[0];
  result.t_ushort.v128[1] = __a.t_ushort.v128[1] > __b.t_ushort.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8us_cmpgt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ushort = __a.t_ushort > __b.t_ushort;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8i_cmpgt)(vec __a, vec __b) {
  vec result;
  result.t_int.v128[0] = __a.t_int.v128[0] > __b.t_int.v128[0];
  result.t_int.v128[1] = __a.t_int.v128[1] > __b.t_int.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4i_cmpgt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_int = __a.t_int > __b.t_int;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8ui_cmpgt)(vec __a, vec __b) {
  vec result;
  result.t_uint.v128[0] = __a.t_uint.v128[0] > __b.t_uint.v128[0];
  result.t_uint.v128[1] = __a.t_uint.v128[1] > __b.t_uint.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4ui_cmpgt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uint = __a.t_uint > __b.t_uint;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8f_cmpgt)(vec __a, vec __b) {
  vec result;
  result.t_float.v128[0] = __a.t_float.v128[0] > __b.t_float.v128[0];
  result.t_float.v128[1] = __a.t_float.v128[1] > __b.t_float.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4f_cmpgt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_float = __a.t_float > __b.t_float;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4d_cmpgt)(vec __a, vec __b) {
  vec result;
  result.t_double.v128[0] = __a.t_double.v128[0] > __b.t_double.v128[0];
  result.t_double.v128[1] = __a.t_double.v128[1] > __b.t_double.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2d_cmpgt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_double = __a.t_double > __b.t_double;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ll_cmpgt)(vec __a, vec __b) {
  vec result;
  result.t_long_long.v128[0] = __a.t_long_long.v128[0] > __b.t_long_long.v128[0];
  result.t_long_long.v128[1] = __a.t_long_long.v128[1] > __b.t_long_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ll_cmpgt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_long_long = __a.t_long_long > __b.t_long_long;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ull_cmpgt)(vec __a, vec __b) {
  vec result;
  result.t_ulong_long.v128[0] = __a.t_ulong_long.v128[0] > __b.t_ulong_long.v128[0];
  result.t_ulong_long.v128[1] = __a.t_ulong_long.v128[1] > __b.t_ulong_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ull_cmpgt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ulong_long = __a.t_ulong_long > __b.t_ulong_long;
  return result;
}

/* -------- end header ------ */

// /---------------start of header ----------- //

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32c_cmplt)(vec __a, vec __b) {
  vec result;
  result.t_char.v128[0] = __a.t_char.v128[0] < __b.t_char.v128[0];
  result.t_char.v128[1] = __a.t_char.v128[1] < __b.t_char.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16c_cmplt)(vec128 __a, vec128 __b) {
	vec128 result;
	result.t_char = __a.t_char < __b.t_char;
	return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32sc_cmplt)(vec __a, vec __b) {
	vec result;
	result.t_schar.v128[0] = __a.t_schar.v128[0] < __b.t_schar.v128[0];
	result.t_schar.v128[1] = __a.t_schar.v128[1] < __b.t_schar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16sc_cmplt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_schar = __a.t_schar < __b.t_schar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v32uc_cmplt)(vec __a, vec __b) {
	vec result;
	result.t_uchar.v128[0] = __a.t_uchar.v128[0] < __b.t_uchar.v128[0];
	result.t_uchar.v128[1] = __a.t_uchar.v128[1] < __b.t_uchar.v128[1];
	return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v16uc_cmplt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uchar = __a.t_uchar < __b.t_uchar;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16s_cmplt)(vec __a, vec __b) {
  vec result;
  result.t_short.v128[0] = __a.t_short.v128[0] < __b.t_short.v128[0];
  result.t_short.v128[1] = __a.t_short.v128[1] < __b.t_short.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8s_cmplt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_short = __a.t_short < __b.t_short;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v16us_cmplt)(vec __a, vec __b) {
  vec result;
  result.t_ushort.v128[0] = __a.t_ushort.v128[0] < __b.t_ushort.v128[0];
  result.t_ushort.v128[1] = __a.t_ushort.v128[1] < __b.t_ushort.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v8us_cmplt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ushort = __a.t_ushort < __b.t_ushort;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8i_cmplt)(vec __a, vec __b) {
  vec result;
  result.t_int.v128[0] = __a.t_int.v128[0] < __b.t_int.v128[0];
  result.t_int.v128[1] = __a.t_int.v128[1] < __b.t_int.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4i_cmplt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_int = __a.t_int < __b.t_int;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8ui_cmplt)(vec __a, vec __b) {
  vec result;
  result.t_uint.v128[0] = __a.t_uint.v128[0] < __b.t_uint.v128[0];
  result.t_uint.v128[1] = __a.t_uint.v128[1] < __b.t_uint.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4ui_cmplt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_uint = __a.t_uint < __b.t_uint;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v8f_cmplt)(vec __a, vec __b) {
  vec result;
  result.t_float.v128[0] = __a.t_float.v128[0] < __b.t_float.v128[0];
  result.t_float.v128[1] = __a.t_float.v128[1] < __b.t_float.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v4f_cmplt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_float = __a.t_float < __b.t_float;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4d_cmplt)(vec __a, vec __b) {
  vec result;
  result.t_double.v128[0] = __a.t_double.v128[0] < __b.t_double.v128[0];
  result.t_double.v128[1] = __a.t_double.v128[1] < __b.t_double.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2d_cmplt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_double = __a.t_double < __b.t_double;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ll_cmplt)(vec __a, vec __b) {
  vec result;
  result.t_long_long.v128[0] = __a.t_long_long.v128[0] < __b.t_long_long.v128[0];
  result.t_long_long.v128[1] = __a.t_long_long.v128[1] < __b.t_long_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ll_cmplt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_long_long = __a.t_long_long < __b.t_long_long;
  return result;
}

static inline vec __FUNC_ATTR_SSE _FUNC_SSE(v4ull_cmplt)(vec __a, vec __b) {
  vec result;
  result.t_ulong_long.v128[0] = __a.t_ulong_long.v128[0] < __b.t_ulong_long.v128[0];
  result.t_ulong_long.v128[1] = __a.t_ulong_long.v128[1] < __b.t_ulong_long.v128[1];
  return result;
}

static inline vec128 __FUNC_ATTR_SSE _FUNC_SSE(v2ull_cmplt)(vec128 __a, vec128 __b) {
  vec128 result;
  result.t_ulong_long = __a.t_ulong_long < __b.t_ulong_long;
  return result;
}

/* -------- end header ------ */

#undef __FUNC_ATTR_SSE
#undef __SIMPL_TYPE_ONLY

#endif /* __FUNCTION_SSE_H__ */
