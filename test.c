#include <string.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <immintrin.h>

#define VEC_SIZE 32

size_t _strlen_sse(const char *s)
{
	if (__builtin_expect(s == NULL, 0))
		return 0;
	
	const char		*ptr = s;
	__m128i			zero = _mm_setzero_si128();
	size_t			misalignment = (size_t)s & 15;
	/*
		* If the pointer is not aligned on a 16 bytes boundary, 
		* the function handles the initial bytes separately.
		* It loads 16 bytes from the memory pointed by ptr and checks if there is a zero byte in the chunk.
	*/
	if (misalignment)
	{
		__m128i data = _mm_loadu_si128((const __m128i *)s);
		__m128i cmp = _mm_cmpeq_epi8(data, zero);
		uint32_t mask = _mm_movemask_epi8(cmp);

		if (mask)
			return (s - ptr) + __builtin_ctz(mask);
		s += 16 - misalignment;
	}
	/*
		* Prefetch the next 32 bytes to improve performance.
		* The _MM_HINT_NTA hint is used to indicate that the data is not accessed again soon.
		* This hint is useful when the data is not accessed sequentially.
		* The _MM_HINT_T0 hint is used to indicate that the data is accessed soon.
		* This hint is useful when the data is accessed sequentially.
	*/
	while (1)
	{
		__m128i data = _mm_loadu_si128((const __m128i *)s);
		__m128i cmp = _mm_cmpeq_epi8(data, zero);
		uint32_t mask = _mm_movemask_epi8(cmp);
		if (mask)
			return (s - ptr) + __builtin_ctz(mask);
		s += 16;
	}
}

#define SIMPLV_USE_SSE
#include "includes/simpl.h"

size_t _strlen_vec(const char *s)  
{
    const char		*ptr = s;
    vec				zero = v256b_set1_char(0);
    size_t			offset = (uintptr_t)ptr & (VEC_SIZE - 1);
    
	if (offset != 0) 
    {
        size_t align_size = VEC_SIZE - offset;
        vec data = v256b_loadu((const uvec *)ptr);
        vec cmp = v32c_cmpeq(data, zero);
        int mask = v32c_movemask(cmp);
        if (mask != 0)
        {
            return (size_t)__builtin_ctz(mask);
        }
        ptr += align_size;
    }
    while (1) 
    {
        vec data = v256b_loadu((const uvec *)ptr);
        vec cmp = v32c_cmpeq(data, zero);
        int mask = v32c_movemask(cmp);
        if (mask != 0)
        {
            return (size_t)(ptr - s) + (size_t)__builtin_ctz(mask);
        }
        ptr += VEC_SIZE;
    }
	_mm256_zeroupper();

    return 0;
}

/* size_t _strlen_avx(const char *s)  */
/* { */
/* 	const char		*ptr = s; */
/* 	const __m256i	zero = _mm256_setzero_si256(); */
/* 	size_t			offset = (uintptr_t)ptr & (VEC_SIZE - 1); */
/*  */
/* 	if (offset != 0)  */
/* 	{ */
/* 		size_t align_size = VEC_SIZE - offset; */
/* 		__m256i data = _mm256_loadu_si256((const __m256i *)ptr); */
/* 		__m256i cmp = _mm256_cmpeq_epi8(data, zero); */
/*         int mask = _mm256_movemask_epi8(cmp); */
/*         if (mask != 0) */
/*         { */
/*             return (size_t)__builtin_ctz(mask); */
/*         } */
/*         ptr += align_size; */
/*     } */
/*  */
/*     while (1)  */
/*     { */
/*         __m256i data = _mm256_loadu_si256((const __m256i *)ptr); */
/*         __m256i cmp = _mm256_cmpeq_epi8(data, zero); */
/*         int mask = _mm256_movemask_epi8(cmp); */
/*         if (mask != 0) */
/*         { */
/*             return (size_t)(ptr - s) + (size_t)__builtin_ctz(mask); */
/*         } */
/*         ptr += VEC_SIZE; */
/*     } */
/*  */
/*     return 0; */
/* } */


int main(void)
{
	size_t iterations = 100;
    struct timespec start, end;
    double cpu_time_used;
	char *str = malloc(1024 * 1024 * 1024);
	memset(str, 1, 1024 * 1024 * 1024);


	int size;
	int size_real;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t i = 0; i < iterations; i++) {
		 size =_strlen_vec(str);
	}
    clock_gettime(CLOCK_MONOTONIC, &end);
    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("vec: %f seconds\n", cpu_time_used);
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t i = 0; i < iterations; i++) {
		 size_real =_strlen_sse(str);
	}
    clock_gettime(CLOCK_MONOTONIC, &end);
    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("sse: %f seconds\n", cpu_time_used);
	printf("%d\n", size);
	printf("%d\n", size_real);
	free(str);
}
