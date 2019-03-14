#include "ft_des.h"

void	ft_des_derive_encryption_round_key
(
	t_byte1 input_key[FT_DES_REDUCED_KEY_SIZE],
	t_byte1 round,
	t_byte1 round_key[FT_DES_ROUND_KEY_SIZE]
)
{
	if (round == 1 || round == 2 || round == 9 || round == 16)
	{
		ft_des_rotate_half_key_left(input_key, 1);
		ft_des_rotate_half_key_left(input_key + FT_DES_REDUCED_KEY_SIZE / 2, 1);
	}
	else
	{
		ft_des_rotate_half_key_left(input_key, 2);
		ft_des_rotate_half_key_left(input_key + FT_DES_REDUCED_KEY_SIZE / 2, 2);
	}
	ft_des_key_permuted_choice_two(input_key, round_key);
}