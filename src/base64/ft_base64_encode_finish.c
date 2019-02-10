#include "ft_base64.h"
#include "libft.h"

void		ft_base64_encode_finish
(
	t_base64_ctx *ctx,
	t_byte8 reminder,
	t_byte1 *buffer
)
{
	ft_bzero(buffer + reminder, FT_BASE64_TRANS_SIZE - reminder);
	ft_base64_transform(ctx, buffer);
	ft_memset(ctx->chars + FT_BASE64_CHARS_SIZE - reminder, '=', FT_BASE64_TRANS_SIZE - reminder);
	ft_base64_write(ctx);
	ft_putstr("\n");
}