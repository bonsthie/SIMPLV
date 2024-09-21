#include "includes/simpl.h"
#include <stdio.h>

#include "immintrin.h"

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
	return (result);
}

int main(int ac, char **av)
{
	if (ac < 3)
		return (1);
	cmp_char(av);
	cmp_char_avx(av);
}
