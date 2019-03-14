#include "ft_des.h"

void	ft_des_generate_decryption_round_keys
(
	t_byte1 input_key[FT_DES_INITIAL_KEY_SIZE],
	t_byte1 keys[FT_DES_ROUND_COUNT][FT_DES_ROUND_KEY_SIZE]
)
{
	t_byte1 reduced_key[FT_DES_REDUCED_KEY_SIZE];
	int i;

	ft_des_key_permuted_choice_one(input_key, reduced_key);
	i = 1;
	while(i <= FT_DES_ROUND_COUNT)
	{
		ft_des_derive_decryption_round_key(reduced_key, i, keys[i - 1]);
		i++;
	}
}