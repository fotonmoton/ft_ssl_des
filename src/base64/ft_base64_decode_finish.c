#include "ft_base64.h"
#include "libft.h"

void		ft_base64_decode_finish
(
	t_base64_ctx *ctx,
	t_base64_decode_buffer *buff
)
{
	t_byte8 buffer_index;
	t_byte8	padding_size;
	// t_byte1	chars[FT_BASE64_ENCODE_BLOCK_SIZE];

	buffer_index = buff->readed % FT_BASE64_DECODE_BLOCK_SIZE;
	padding_size = FT_BASE64_DECODE_BLOCK_SIZE - buffer_index;
	if (!buff->readed)
		return ;
	if (!buffer_index)
	{
		write(ctx->output_fd, "\n", 1);
		return ;
	}
	// ft_bzero(&buff->block[buffer_index], padding_size);
	// ft_base64_encode_transform(ctx, buff->block, chars);
	// ft_memset(chars + FT_BASE64_DECODE_BLOCK_SIZE - padding_size, '=',
	// 	padding_size);
	// write(ctx->output_fd, chars, FT_BASE64_DECODE_BLOCK_SIZE);
	// write(ctx->output_fd, "\n", 1);
}