/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_encode_chunk.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:11:15 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:11:28 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base64.h"
#include "libft.h"

static void	ft_base64_encode_write
(
	t_base64_ctx *ctx,
	t_byte1 buff[FT_BASE64_ENCODE_BLOCK_SIZE]
)
{
	t_byte1 chars[FT_BASE64_DECODE_BLOCK_SIZE];

	ft_base64_encode_transform(ctx, buff, chars);
	write(ctx->output_fd, chars, FT_BASE64_DECODE_BLOCK_SIZE);
}

void		ft_base64_encode_chunk
(
	t_base64_ctx *ctx,
	t_byte8 message_len,
	t_byte1 *message,
	t_base64_encode_buffer *buff
)
{
	t_byte8		free_space_in_buffer;
	t_byte8		buffer_index;
	t_byte8		idx;

	buffer_index = buff->readed % FT_BASE64_ENCODE_BLOCK_SIZE;
	buff->readed += message_len;
	free_space_in_buffer = FT_BASE64_ENCODE_BLOCK_SIZE - buffer_index;
	if (message_len >= free_space_in_buffer)
	{
		ft_memcpy(&buff->block[buffer_index], message, free_space_in_buffer);
		ft_base64_encode_write(ctx, buff->block);
		idx = free_space_in_buffer;
		while (idx + FT_BASE64_ENCODE_BLOCK_SIZE <= message_len)
		{
			ft_base64_encode_write(ctx, &message[idx]);
			idx += FT_BASE64_ENCODE_BLOCK_SIZE;
		}
		buffer_index = 0;
	}
	else
		idx = 0;
	ft_memcpy(&buff->block[buffer_index], &message[idx], message_len - idx);
}
