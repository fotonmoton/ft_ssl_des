#include <unistd.h>
#include "libft.h"
#include "ft_base64.h"

static void	ft_base64_decode_write
(
	t_base64_ctx *ctx,
	t_byte1 *block
)
{
	t_byte1		decoded_block[FT_BASE64_ENCODE_BLOCK_SIZE];

	ft_base64_decode_transform(ctx, block, decoded_block);
	if (block[3] == '=' && block[2] == '=')
		write(ctx->output_fd, decoded_block, FT_BASE64_ENCODE_BLOCK_SIZE - 2);
	else if (block[3] == '=')
		write(ctx->output_fd, decoded_block, FT_BASE64_ENCODE_BLOCK_SIZE - 1);
	else
		write(ctx->output_fd, decoded_block, FT_BASE64_ENCODE_BLOCK_SIZE);
}

void		ft_base64_decode_chunk
(
	t_base64_ctx *ctx,
	t_byte8 message_len,
	t_byte1 *message,
	t_base64_decode_buffer *buff
)
{
	t_byte8		free_space_in_buffer;
	t_byte8		buffer_index;
	t_byte8		idx;

	buffer_index = buff->readed % FT_BASE64_DECODE_BLOCK_SIZE;
	buff->readed += message_len;
	free_space_in_buffer = FT_BASE64_DECODE_BLOCK_SIZE - buffer_index;
	if (message_len >= free_space_in_buffer)
	{
		ft_memcpy(&buff->block[buffer_index], message, free_space_in_buffer);
		ft_base64_decode_write(ctx, buff->block);
		idx = free_space_in_buffer;
		while(idx + FT_BASE64_DECODE_BLOCK_SIZE <= message_len)
		{
			ft_base64_decode_write(ctx, &message[idx]);
			idx += FT_BASE64_DECODE_BLOCK_SIZE;
		}
		buffer_index = 0;
	}
	else
		idx = 0;
	ft_memcpy(&buff->block[buffer_index], &message[idx], message_len - idx);
}