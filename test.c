#include "includes/simpl.h"
#include <time.h>
#include <stdint.h>
#include <stdio.h>

#define VEC_SIZE 32

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
	char *str2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
	char *str = "42378948914897390281942389740978329487940294728908902490870948289412097";


    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t i = 0; i < iterations; i++) {
		_strlen_vec(str);
	}
    clock_gettime(CLOCK_MONOTONIC, &end);
    cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("vec: %f seconds\n", cpu_time_used);
}
