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

static void	bytes_to_bits
(
	t_byte1 bytes[FT_DES_BYTE_BLOCK_SIZE],
	t_byte1 bits[FT_DES_BIT_BLOCK_SIZE]
)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < FT_DES_BYTE_BLOCK_SIZE)
	{
		bits[j] = bytes[i] >> 7 & 1;
		bits[j + 1] = bytes[i] >> 6 & 1;
		bits[j + 2] = bytes[i] >> 5 & 1;
		bits[j + 3] = bytes[i] >> 4 & 1;
		bits[j + 4] = bytes[i] >> 3 & 1;
		bits[j + 5] = bytes[i] >> 2 & 1;
		bits[j + 6] = bytes[i] >> 1 & 1;
		bits[j + 7] = bytes[i] & 1;
		j += FT_DES_BYTE_BLOCK_SIZE;
		i++;
	}
}

static void	bits_to_bytes
(
	t_byte1 bits[FT_DES_BIT_BLOCK_SIZE],
	t_byte1 bytes[FT_DES_BYTE_BLOCK_SIZE]
)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < FT_DES_BYTE_BLOCK_SIZE)
	{
		bytes[i] = bits[j] << 7
					| bits[j + 1] << 6
					| bits[j + 2] << 5
					| bits[j + 3] << 4
					| bits[j + 4] << 3
					| bits[j + 5] << 2
					| bits[j + 6] << 1
					| bits[j + 7];
		j += FT_DES_BYTE_BLOCK_SIZE;
		i++;
	}
}

void	ft_des_process_block
(
	t_byte1 input[FT_DES_BYTE_BLOCK_SIZE],
	t_byte1 keys[FT_DES_ROUND_COUNT][FT_DES_ROUND_KEY_SIZE],
	t_byte1 output[FT_DES_BYTE_BLOCK_SIZE]
)
{
	t_byte1 input_bits[FT_DES_BIT_BLOCK_SIZE];
	t_byte1 output_bits[FT_DES_BIT_BLOCK_SIZE];
	t_byte1 ip_message[FT_DES_BIT_BLOCK_SIZE];
	int i;

	bytes_to_bits(input, input_bits);
	ft_des_initial_permutation(input_bits, ip_message);
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
	ft_des_final_permutation(ip_message, output_bits);
	bits_to_bytes(output_bits, output);
}