#include "ft_des.h"

void	ft_des_final_permutation
(
	t_byte1 before[FT_DES_BIT_BLOCK_SIZE],
	t_byte1 final_permutation[FT_DES_BIT_BLOCK_SIZE]
)
{
	static t_byte1 table[FT_DES_BIT_BLOCK_SIZE] = {
		40,  8, 48, 16, 56, 24, 64, 32,
		39,  7, 47, 15, 55, 23, 63, 31,
		38,  6, 46, 14, 54, 22, 62, 30,
		37,  5, 45, 13, 53, 21, 61, 29,
		36,  4, 44, 12, 52, 20, 60, 28,
		35,  3, 43, 11, 51, 19, 59, 27,
		34,  2, 42, 10, 50, 18, 58, 26,
		33,  1, 41,  9, 49, 17, 57, 25,
	};
	t_byte1	i;

	i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE)
	{
		final_permutation[i] = before[table[i] - 1];
		i++;
	}
}