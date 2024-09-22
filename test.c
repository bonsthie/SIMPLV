#include "includes/simpl.h"
#include <time.h>
#include <stdint.h>
#include <stdio.h>

#include "immintrin.h"


#define VEC_SIZE 32

__m256i cmp_char_avx(char **av)
{
	__m256i result;
	__m256i first;
	__m256i second;

	first = _mm256_set1_epi8(**av);
	av++;
	second = _mm256_set1_epi8(**av);
	result = _mm256_add_epi8(first, second);
	return (result);
}

vec cmp_char(char **av)
{
	vec result;
	vec first;
	vec second;

	first = v256b_set1_char(**av);
	av++;
	second = v256b_set1_char(**av);
	result = v32c_add(first, second);
	av++;
	second = v256b_set1_char(**av);
	result = v32c_add(first, second);
	av++;
	second = v256b_set1_char(**av);
	result = v32c_add(first, second);
	av++;
	second = v256b_set1_char(**av);
	result = v32c_add(first, second);
	av++;
	second = v256b_set1_char(**av);
	result = v32c_add(first, second);
	return (result);
}

size_t _strlen_avx(const char *s) 
{
    const char		*ptr = s;
    const __m256i	zero = _mm256_set1_epi8(0);
    size_t			offset = (uintptr_t)ptr & (VEC_SIZE - 1);
    
	if (offset != 0) 
    {
        size_t align_size = VEC_SIZE - offset;
        __m256i data = _mm256_loadu_si256((const __m256i *)ptr);
        __m256i cmp = _mm256_cmpeq_epi8(data, zero);
        int mask = _mm256_movemask_epi8(cmp);
        if (mask != 0)
        {
            return (size_t)__builtin_ctz(mask);
        }
        ptr += align_size;
    }
    while (1) 
    {
        __m256i data = _mm256_loadu_si256((const __m256i *)ptr);
        __m256i cmp = _mm256_cmpeq_epi8(data, zero);
        int mask = _mm256_movemask_epi8(cmp);
        if (mask != 0)
        {
            return (size_t)(ptr - s) + (size_t)__builtin_ctz(mask);
        }
        ptr += VEC_SIZE;
    }

    return 0;
}

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

    return 0;
}

int main(void)
{
	size_t iterations = 100;
    struct timespec start, end;
    double cpu_time_used;
	char *str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t i = 0; i < iterations; i++) {
		_strlen_avx(str);
	}
    clock_gettime(CLOCK_MONOTONIC, &end);
    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("avx: %f seconds\n", cpu_time_used);

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t i = 0; i < iterations; i++) {
		_strlen_vec(str);
	}
    clock_gettime(CLOCK_MONOTONIC, &end);
    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("vec: %f seconds\n", cpu_time_used);
}
