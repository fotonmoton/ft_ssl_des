#include "ft_base64.h"
#include "libft.h"

t_byte8		ft_base64_chunk
(
	t_base64_ctx *ctx,
	t_byte8 len,
	t_byte1 *message
)
{
	t_byte8		free_space_in_buffer;
	t_byte8		i;

	free_space_in_buffer = FT_BASE64_TRANS_SIZE - ctx->in_buffer;
	if (len >= free_space_in_buffer)
	{
		ft_memcpy(&ctx->buffer[ctx->in_buffer], message, free_space_in_buffer);
		ft_base64_transform(ctx, ctx->buffer);
		ft_base64_write(ctx);
		i = free_space_in_buffer;
		while(i + FT_BASE64_TRANS_SIZE <= len)
		{
			ft_base64_transform(ctx, &message[i]);
			ft_base64_write(ctx);
			i += FT_BASE64_TRANS_SIZE;
		}

	}
}