# include "ft_base64.h"
# include <unistd.h>

void		ft_base64_write(t_base64_ctx *ctx)
{
	write(ctx->output_fd, ctx->chars, FT_BASE64_CHARS_SIZE);
}