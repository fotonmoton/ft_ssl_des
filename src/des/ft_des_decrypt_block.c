#include "ft_des.h"

void	ft_des_encrypt_block
(
	t_byte1 plaintext[FT_DES_BIT_BLOCK_SIZE],
	t_byte1 keys[FT_DES_ROUND_COUNT][FT_DES_FEISTEL_FUNCTION_KEY_SIZE],
	t_byte1 cyphertext[FT_DES_BIT_BLOCK_SIZE]
)
{
	t_byte1 ip_message[FT_DES_BIT_BLOCK_SIZE];
	int i;

	ft_des_initial_permutation(plaintext, ip_message);
	i = 1;
	while(i <= FT_DES_ROUND_COUNT)
	{
		if (i % 2 != 0)
			ft_des_encryption_round(ip_message, ip_message + 32, keys[i - 1]);
		else
			ft_des_encryption_round(ip_message + 32, ip_message, keys[i - 1]);
		i++;
	}
	ft_des_switch_message_halves(ip_message);
	ft_des_final_permutation(ip_message, cyphertext);
}