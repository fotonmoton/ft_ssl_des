/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pbkdf2_sha256.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:15:38 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:17:16 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pbkdf2.h"
#include "ft_sha.h"
#include "libft.h"

static void	set_key_and_message
(
	t_pbkdf2_sha256_ctx *ctx,
	t_hmac_sha256_ctx *hmac_ctx
)
{
	hmac_ctx->key = ctx->pass;
	hmac_ctx->key_size = ctx->pass_len;
	hmac_ctx->msg = ctx->salt;
	hmac_ctx->msg_size = ctx->salt_len;
}

static void	xor
(
	unsigned char x[FT_SHA256_DIGEST_LENGTH_BYTE],
	unsigned char y[FT_SHA256_DIGEST_LENGTH_BYTE],
	unsigned char result[FT_SHA256_DIGEST_LENGTH_BYTE]
)
{
	unsigned int i;

	i = 0;
	while (i < FT_SHA256_DIGEST_LENGTH_BYTE)
	{
		result[i] = x[i] ^ y[i];
		i++;
	}
}

static int	ceil
(
	unsigned int x,
	unsigned int y
)
{
	return (1 + ((x - 1) / y));
}

static void	block_function
(
	t_pbkdf2_sha256_ctx *ctx,
	t_hmac_sha256_ctx *hmac_ctx,
	unsigned int iteration,
	unsigned char block[FT_SHA256_DIGEST_LENGTH_BYTE]
)
{
	unsigned int		i;
	unsigned char		c[4];
	unsigned char		prev[FT_SHA256_DIGEST_LENGTH_BYTE];

	c[0] = (iteration >> 24) & 0xff;
	c[1] = (iteration >> 16) & 0xff;
	c[2] = (iteration >> 8) & 0xff;
	c[3] = (iteration >> 0) & 0xff;
	ft_hmac_sha256_start(hmac_ctx);
	ft_hmac_sha256_update(hmac_ctx, hmac_ctx->msg, hmac_ctx->msg_size);
	ft_hmac_sha256_update(hmac_ctx, c, 4);
	ft_hmac_sha256_finish(hmac_ctx, prev);
	ft_memcpy(block, prev, FT_SHA256_DIGEST_LENGTH_BYTE);
	i = 1;
	while (i < ctx->iterations)
	{
		ft_hmac_sha256_start(hmac_ctx);
		ft_hmac_sha256_update(hmac_ctx, prev, FT_SHA256_DIGEST_LENGTH_BYTE);
		ft_hmac_sha256_finish(hmac_ctx, prev);
		xor(prev, block, block);
		i++;
	}
}

void		ft_pbkdf2_sha256
(
	t_pbkdf2_sha256_ctx *c
)
{
	t_hmac_sha256_ctx	hmac_ctx;
	unsigned char		block[FT_SHA256_DIGEST_LENGTH_BYTE];
	unsigned int		block_count;
	unsigned int		i;
	unsigned int		key_index;

	ft_hmac_sha256_init_ctx(&hmac_ctx);
	set_key_and_message(c, &hmac_ctx);
	block_count = ceil(c->key_len, FT_SHA256_DIGEST_LENGTH_BYTE);
	i = 1;
	key_index = 0;
	while (i < block_count)
	{
		block_function(c, &hmac_ctx, i, block);
		ft_memcpy(c->key + key_index, block, FT_SHA256_DIGEST_LENGTH_BYTE);
		key_index += i * FT_SHA256_DIGEST_LENGTH_BYTE;
		i++;
	}
	block_function(c, &hmac_ctx, i, block);
	ft_memcpy(c->key + key_index, block,
	c->key_len - (block_count - 1) * FT_SHA256_DIGEST_LENGTH_BYTE);
}
