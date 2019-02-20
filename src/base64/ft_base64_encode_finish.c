#include "ft_base64.h"
#include "libft.h"

void		ft_base64_encode_finish
(
	t_base64_ctx *ctx,
	t_base64_encode_buffer *buff
)
{
	t_byte8 buffer_index;
	t_byte8	padding_size;
	t_byte1	chars[FT_BASE64_CHARS_SIZE];

	buffer_index = buff->readed % FT_BASE64_TRANS_SIZE;
	padding_size = FT_BASE64_TRANS_SIZE - buffer_index;
	if (!buff->readed)
		return ;
	if (!buffer_index)
	{
		ft_putstr("\n");
		return ;
	}
	ft_bzero(&buff->block[buffer_index], padding_size);
	ft_base64_encode_transform(ctx, buff->block, chars);
	ft_memset(chars + FT_BASE64_CHARS_SIZE - padding_size, '=', padding_size);
	write(ctx->output_fd, chars, FT_BASE64_CHARS_SIZE);
	ft_putstr("\n");
}