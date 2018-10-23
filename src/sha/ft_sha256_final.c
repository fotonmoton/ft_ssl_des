/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_final.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:16:08 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:16:26 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"
#include "libft.h"

static void	fill_digest
(
	t_byte1 digest[FT_SHA256_DIGEST_LENGTH_BYTE],
	t_sha256_ctx *ctx
)
{
	ft_sha256_encode_register(digest, ctx->a);
	ft_sha256_encode_register(&digest[4], ctx->b);
	ft_sha256_encode_register(&digest[8], ctx->c);
	ft_sha256_encode_register(&digest[12], ctx->d);
	ft_sha256_encode_register(&digest[16], ctx->e);
	ft_sha256_encode_register(&digest[20], ctx->f);
	ft_sha256_encode_register(&digest[24], ctx->g);
	ft_sha256_encode_register(&digest[28], ctx->h);
}

void		ft_sha256_final
(
	t_byte1 digest[FT_SHA256_DIGEST_LENGTH_BYTE],
	t_sha256_ctx *ctx
)
{
	t_byte1 length_as_bytes[FT_SHA256_MESSAGE_LENGTH_BYTE];
	t_byte1 padding[FT_SHA256_BLOCK_SIZE];
	t_byte8 buff_index;
	t_byte8 padding_len;

	ft_sha256_encode_len(length_as_bytes, ctx->bit_len);
	buff_index = (ctx->bit_len / 8) % 64;
	padding_len = (buff_index < 56) ? (56 - buff_index) : (120 - buff_index);
	ft_sha256_padding(padding);
	ft_sha256_update(ctx, padding, padding_len);
	ft_sha256_update(ctx, length_as_bytes, FT_SHA256_MESSAGE_LENGTH_BYTE);
	fill_digest(digest, ctx);
}
