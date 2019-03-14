#include "ft_des.h"

void	ft_des_key_permuted_choice_two
(
	t_byte1 input_key[FT_DES_REDUCED_KEY_SIZE],
	t_byte1 round_key[FT_DES_ROUND_KEY_SIZE]
)
{
	static t_byte1 table[FT_DES_ROUND_KEY_SIZE] = {
		14, 17, 11, 24,  1,  5,  3, 28,
		15,  6, 21, 10, 23, 19, 12,  4,
		26,  8, 16,  7, 27, 20, 13,  2,
		41, 52, 31, 37, 47, 55, 30, 40,
		51, 45, 33, 48, 44, 49, 39, 56,
		34, 53, 46, 42, 50, 36, 29, 32,
	};
	int i;

	i = 0;
	while(i < FT_DES_ROUND_KEY_SIZE)
	{
		round_key[i] = input_key[table[i] - 1];
		i++;
	}
}