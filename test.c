#include "includes/simpl.h"
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <stdio.h>

#define VEC_SIZE 32

size_t _strlen_vec(const char *s) 
{
	__m256i test;
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
	char *str = malloc(1024 * 1024);
	memset(str, 1, 1024 * 1024);


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
		 size_real =strlen(str);
	}
    clock_gettime(CLOCK_MONOTONIC, &end);
    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("vec: %f seconds\n", cpu_time_used);
	printf("%d\n", size);
	printf("%d\n", size_real);
	free(str);
}
