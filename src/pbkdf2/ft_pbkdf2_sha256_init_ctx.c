#include <stddef.h>
#include "ft_pbkdf2.h"

void	ft_pbkdf2_sha256_init_ctx
(
	t_pbkdf2_sha256_ctx *ctx
)
{
	ctx->iterations = 0;
	ctx->key = NULL;
	ctx->pass = NULL;
	ctx->salt = NULL;
	ctx->key_len = 0;
	ctx->pass_len = 0;
	ctx->salt_len = 0;
}