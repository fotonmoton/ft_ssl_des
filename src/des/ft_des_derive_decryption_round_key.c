#include "ft_des.h"

void	ft_des_derive_decryption_round_key
(
	t_byte1 key[FT_DES_REDUCED_KEY_SIZE],
	t_byte1 round,
	t_byte1 round_key[FT_DES_ROUND_KEY_SIZE]
)
{
	if (round == 2 || round == 9 || round == 16)
	{
		ft_des_rotate_half_key_right(key, 1);
		ft_des_rotate_half_key_right(key + FT_DES_REDUCED_KEY_SIZE / 2, 1);
	}
	else if (round != 1)
	{
		ft_des_rotate_half_key_right(key, 2);
		ft_des_rotate_half_key_right(key + FT_DES_REDUCED_KEY_SIZE / 2, 2);
	}
	ft_des_key_permuted_choice_two(key, round_key);
}