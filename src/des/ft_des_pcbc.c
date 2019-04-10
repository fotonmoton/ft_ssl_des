/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_pcbc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:53:37 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:54:07 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

static void	xor
(
	t_byte1 a[FT_DES_BIT_BLOCK_SIZE],
	t_byte1 b[FT_DES_BIT_BLOCK_SIZE]
)
{
	int i;

	i = 0;
	while (i < FT_DES_BIT_BLOCK_SIZE)
	{
		a[i] = a[i] ^ b[i];
		i++;
	}
}

static void	encrypt
(
	t_byte1 input[FT_DES_BYTE_BLOCK_SIZE],
	t_byte1 keys[FT_DES_ROUND_COUNT][FT_DES_ROUND_KEY_SIZE],
	t_byte1 iv[FT_DES_BYTE_BLOCK_SIZE],
	t_byte1 output[FT_DES_BYTE_BLOCK_SIZE]
)
{
	t_byte1		input_bits[FT_DES_BIT_BLOCK_SIZE];
	t_byte1		input_with_iv[FT_DES_BYTE_BLOCK_SIZE];

	ft_des_byte_to_bits(input, FT_DES_BYTE_BLOCK_SIZE, input_bits,
		FT_DES_BIT_BLOCK_SIZE);
	xor(iv, input_bits);
	ft_des_bits_to_bytes(input_bits, FT_DES_BIT_BLOCK_SIZE, input_with_iv,
		FT_DES_BYTE_BLOCK_SIZE);
	ft_des_process_block(input_with_iv, keys, output);
	ft_des_byte_to_bits(output, FT_DES_BYTE_BLOCK_SIZE, iv,
		FT_DES_BIT_BLOCK_SIZE);
	xor(iv, input_bits);
}

static void	decrypt
(
	t_byte1 input[FT_DES_BYTE_BLOCK_SIZE],
	t_byte1 keys[FT_DES_ROUND_COUNT][FT_DES_ROUND_KEY_SIZE],
	t_byte1 iv[FT_DES_BYTE_BLOCK_SIZE],
	t_byte1 output[FT_DES_BYTE_BLOCK_SIZE]
)
{
	t_byte1		output_bits[FT_DES_BIT_BLOCK_SIZE];

	ft_des_process_block(input, keys, output);
	ft_des_byte_to_bits(output, FT_DES_BYTE_BLOCK_SIZE, output_bits,
		FT_DES_BIT_BLOCK_SIZE);
	xor(output_bits, iv);
	ft_des_byte_to_bits(input, FT_DES_BYTE_BLOCK_SIZE, iv,
		FT_DES_BIT_BLOCK_SIZE);
	xor(iv, output_bits);
}

void		ft_des_pcbc
(
	int argc,
	char **argv
)
{
	t_des_ctx ctx;

	ft_des_init_ctx(&ctx);
	ft_des_parse_args(argc, argv, &ctx);
	if (ctx.raw_key && !ctx.raw_iv)
		ft_des_print_error("initialization vector required when key specified");
	ctx.encrypt = encrypt;
	ctx.decrypt = decrypt;
	ft_des(&ctx);
}
