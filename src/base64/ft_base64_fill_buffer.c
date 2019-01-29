#include "libft.h"
#include "ft_base64.h"

void ft_base64_fill_buffer(t_base64_ctx *ctx, t_byte1 *data, t_byte8 size)
{
	ft_memcpy(ctx->block, data, size);
}