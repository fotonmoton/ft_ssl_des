#include "ft_sha.h"
#include "libft.h"

void ft_sha256_init(t_sha256_ctx *ctx)
{
	ctx->a = 0x6a09e667;
	ctx->b = 0xbb67ae85;
	ctx->c = 0x3c6ef372;
	ctx->d = 0xa54ff53a;
	ctx->e = 0x510e527f;
	ctx->f = 0x9b05688c;
	ctx->g = 0x1f83d9ab;
	ctx->h = 0x5be0cd19;

	ctx->bit_len = 0;
	ft_bzero(ctx->block, FT_SHA256_BLOCK_SIZE);
}