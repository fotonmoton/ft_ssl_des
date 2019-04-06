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
	ft_bzero(ctx->salt, FT_DES_BIT_BLOCK_SIZE);
	ft_bzero(ctx->iv, FT_DES_BIT_BLOCK_SIZE);
	ctx->readed = 0;
	ctx->decode = 0;
	ctx->b64 = 0;
	ctx->input_fd = STDIN_FILENO;
	ctx->output_fd = STDOUT_FILENO;
	ctx->raw_password = NULL;
	ctx->raw_salt = NULL;
	ctx->raw_key = NULL;
}