#include "ft_des.h"

static void switch_halves
(
	t_byte1 message[FT_DES_BIT_BLOCK_SIZE]
)
{
	int i;
	int tmp;
	i = 0;
	while(i < FT_DES_BIT_BLOCK_SIZE / 2)
	{
		tmp = message[i];
		message[i] = message[i + FT_DES_BIT_BLOCK_SIZE / 2];
		message[i + FT_DES_BIT_BLOCK_SIZE / 2] = tmp;
		i++;
	}
}

void	ft_des_process_block
(
	t_byte1 input[FT_DES_BIT_BLOCK_SIZE],
	t_byte1 keys[FT_DES_ROUND_COUNT][FT_DES_FEISTEL_FUNCTION_KEY_SIZE],
	t_byte1 output[FT_DES_BIT_BLOCK_SIZE]
)
{
	t_byte1 ip_message[FT_DES_BIT_BLOCK_SIZE];
	int i;

	ft_des_initial_permutation(input, ip_message);
	i = 1;
	while(i <= FT_DES_ROUND_COUNT)
	{
		if (i % 2 != 0)
			ft_des_round(ip_message, ip_message + 32, keys[i - 1]);
		else
			ft_des_round(ip_message + 32, ip_message, keys[i - 1]);
		i++;
	}
	switch_halves(ip_message);
	ft_des_final_permutation(ip_message, output);
}