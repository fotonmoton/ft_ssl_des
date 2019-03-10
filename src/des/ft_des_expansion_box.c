#include "ft_des.h"

void	ft_des_expansion_box
(
	t_byte1 half[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 expanded[FT_DES_EXPANDED_HALF_BLOCK_SIZE]
)
{
	static t_byte1 permutation_table[FT_DES_EXPANDED_HALF_BLOCK_SIZE] = {
		32,  1,  2,  3,  4,  5,
		 4,  5,  6,  7,  8,  9,
		 8,  9, 10, 11, 12, 13,
		12, 13, 14, 15, 16, 17,
		16, 17, 18, 19, 20, 21,
		20, 21, 22, 23, 24, 25,
		24, 25, 26, 27, 28, 29,
		28, 29, 30, 31, 32,  1,
	};
	int i;

	i = 0;
	while(i< FT_DES_EXPANDED_HALF_BLOCK_SIZE)
	{
		expanded[i] = half[permutation_table[i] - 1];
		i++;
	}
}