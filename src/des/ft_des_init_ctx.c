#include <unistd.h>
#include "ft_des.h"
#include "libft.h"

void	ft_des_init_ctx
(
	t_des_ctx *ctx
)
{
	int i;

	i = 0;
	while(i < FT_DES_ROUND_COUNT)
	{
		ft_bzero(ctx->round_keys[i], FT_DES_ROUND_KEY_SIZE);
		i++;
	}
	ft_bzero(ctx->key, FT_DES_INITIAL_KEY_SIZE);
	ft_bzero(ctx->buffer, FT_DES_BYTE_BLOCK_SIZE);
	ctx->readed = 0;
	ctx->decode = 0;
	ctx->b64 = 0;
	ctx->output_in_base64 = 0;
	ctx->input_fd = STDIN_FILENO;
	ctx->output_fd = STDOUT_FILENO;
	ft_base64_init(&ctx->b64_ctx);
	ft_base64_init_encode_buffer(&ctx->b64_encode_buffer);
	ft_base64_init_decode_buffer(&ctx->b64_decode_buffer);
}