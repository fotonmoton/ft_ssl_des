#include "ft_des.h"

static void xor
(
	t_byte1 left_half[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 f_function_result[FT_DES_BIT_BLOCK_SIZE / 2]
)
{
	int i;

	i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE / 2)
	{
		left_half[i] = left_half[i] ^ f_function_result[i];
		i++;
	}
}

void	ft_des_round
(
	t_byte1 left_half[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 right_half[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 round_key[FT_DES_FEISTEL_FUNCTION_KEY_SIZE]
)
{
	t_byte1 feistel_function_result[FT_DES_BIT_BLOCK_SIZE / 2];

	ft_des_feistel_function(right_half, round_key, feistel_function_result);
	xor(left_half, feistel_function_result);
}