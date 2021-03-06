/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_encode_process_chunk.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:32:07 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:32:37 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_des.h"
#include "libft.h"

static void	ft_des_ecb_write
(
	t_byte1 buffer[FT_DES_BYTE_BLOCK_SIZE],
	t_des_ctx *ctx
)
{
	t_byte1 cyphertext[FT_DES_BYTE_BLOCK_SIZE];

	ctx->encrypt(buffer, ctx->round_keys, ctx->iv, cyphertext);
	write(ctx->output_fd, cyphertext, FT_DES_BYTE_BLOCK_SIZE);
}

void		ft_des_encode_process_chunk
(
	t_des_ctx *ctx,
	t_byte8 readed,
	t_byte1 buffer[FT_DES_READ_SIZE]
)
{
	t_byte8		free_space_in_buffer;
	t_byte8		buffer_index;
	t_byte8		idx;

	buffer_index = ctx->readed % FT_DES_BYTE_BLOCK_SIZE;
	ctx->readed += readed;
	free_space_in_buffer = FT_DES_BYTE_BLOCK_SIZE - buffer_index;
	if (readed >= free_space_in_buffer)
	{
		ft_memcpy(&ctx->buffer[buffer_index], buffer, free_space_in_buffer);
		ft_des_ecb_write(ctx->buffer, ctx);
		idx = free_space_in_buffer;
		while (idx + FT_DES_BYTE_BLOCK_SIZE <= readed)
		{
			ft_des_ecb_write(&buffer[idx], ctx);
			idx += FT_DES_BYTE_BLOCK_SIZE;
		}
		buffer_index = 0;
	}
	else
		idx = 0;
	ft_memcpy(&ctx->buffer[buffer_index], &buffer[idx], readed - idx);
}
