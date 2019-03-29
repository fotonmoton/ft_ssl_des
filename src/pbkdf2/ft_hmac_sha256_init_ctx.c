#include <stddef.h>
#include "ft_pbkdf2.h"
#include "ft_sha.h"
#include "libft.h"

void ft_hmac_sha256_init_ctx
(
	t_hmac_sha256_ctx *ctx
)
{
	ctx->key = NULL;
	ctx->msg = NULL;
	ctx->key_size = 0;
	ctx->msg_size = 0;
	ft_bzero(ctx->opad, FT_SHA256_BLOCK_SIZE);
	ft_bzero(ctx->ipad, FT_SHA256_BLOCK_SIZE);
}