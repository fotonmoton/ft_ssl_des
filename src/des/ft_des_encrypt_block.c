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

void	ft_des_encrypt_block
(
	t_byte1 plaintext[FT_DES_BIT_BLOCK_SIZE],
	t_byte1 key[FT_DES_INITIAL_KEY_SIZE],
	t_byte1 cyphertext[FT_DES_BIT_BLOCK_SIZE]
)
{
	t_byte1 ip_message[FT_DES_BIT_BLOCK_SIZE];
	t_byte1 reduced_key[FT_DES_REDUCED_KEY_SIZE];
	t_byte1 round_key[FT_DES_FEISTEL_FUNCTION_KEY_SIZE];
	int i;

	ft_des_initial_permutation(plaintext, ip_message);
	ft_des_key_permuted_choice_one(key, reduced_key);
	i = 1;
	while(i <= FT_DES_ROUND_COUNT)
	{
		ft_des_derive_encryption_round_key(reduced_key, i, round_key);
		if (i % 2 != 0)
			ft_des_encryption_round(ip_message, ip_message + 32, round_key);
		else
			ft_des_encryption_round(ip_message + 32, ip_message, round_key);
		i++;
	}
	switch_halves(ip_message);
	ft_des_final_permutation(ip_message, cyphertext);
}