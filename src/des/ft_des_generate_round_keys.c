#include "ft_des.h"

void	ft_des_generate_round_keys
(
	t_byte1 key[FT_DES_INITIAL_KEY_SIZE],
	t_byte1 round_keys[FT_DES_ROUND_COUNT][FT_DES_FEISTEL_FUNCTION_KEY_SIZE]
)
{
	int i;

	i = 1;
	while(i <= FT_DES_ROUND_COUNT)
	{
		ft_des_derive_encryption_round_key(key, i, round_keys[i - 1]);
		i++;
	}
}