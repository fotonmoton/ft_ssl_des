#include "ft_base64.h"
#include "libft.h"

void		ft_base64_encode_finish
(
	t_base64_ctx *ctx,
	t_byte8 reminder,
	t_byte1 *buffer
)
{
	t_byte8 padding_size;

	if (!reminder)
	{
		ft_putstr("\n");
		return ;
	}
	padding_size = reminder == 2 ? 1 : 2;
	ft_bzero(buffer + reminder, FT_BASE64_TRANS_SIZE - reminder);
	ft_base64_transform(ctx, buffer);
	ft_memset(ctx->chars + FT_BASE64_CHARS_SIZE - padding_size, '=', FT_BASE64_CHARS_SIZE - padding_size);
	ft_base64_write(ctx);
	ft_putstr("\n");
}