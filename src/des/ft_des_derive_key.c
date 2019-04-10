/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_derive_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:29:33 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:29:40 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"
#include "ft_pbkdf2.h"
#include "libft.h"

void	ft_des_derive_key_and_iv
(
	t_byte1 key[FT_DES_BIT_BLOCK_SIZE],
	t_byte1 iv[FT_DES_BIT_BLOCK_SIZE],
	char salt[FT_DES_BYTE_BLOCK_SIZE],
	char *pass
)
{
	t_pbkdf2_sha256_ctx	pbkdf_ctx;
	t_byte1				key_iv[FT_DES_BYTE_BLOCK_SIZE * 2];
	t_byte1				key_iv_bit[FT_DES_BIT_BLOCK_SIZE * 2];

	pbkdf_ctx.iterations = 10000;
	pbkdf_ctx.key = key_iv;
	pbkdf_ctx.salt_len = FT_DES_BYTE_BLOCK_SIZE;
	pbkdf_ctx.key_len = FT_DES_BYTE_BLOCK_SIZE * 2;
	pbkdf_ctx.pass_len = ft_strlen(pass);
	pbkdf_ctx.pass = (t_byte1 *)pass;
	pbkdf_ctx.salt = (t_byte1 *)salt;
	ft_pbkdf2_sha256(&pbkdf_ctx);
	ft_des_byte_to_bits(key_iv, FT_DES_BYTE_BLOCK_SIZE * 2, key_iv_bit,
		FT_DES_BIT_BLOCK_SIZE * 2);
	ft_memcpy(key, key_iv_bit, FT_DES_BIT_BLOCK_SIZE);
	ft_memcpy(iv, key_iv_bit + FT_DES_BIT_BLOCK_SIZE, FT_DES_BIT_BLOCK_SIZE);
}
