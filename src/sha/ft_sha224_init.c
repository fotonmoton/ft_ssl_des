#include "ft_sha.h"
#include "libft.h"

void ft_sha224_init(t_sha256_ctx *ctx)
{
	ctx->a = 0xc1059ed8;
	ctx->b = 0x367cd507;
	ctx->c = 0x3070dd17;
	ctx->d = 0xf70e5939;
	ctx->e = 0xffc00b31;
	ctx->f = 0x68581511;
	ctx->g = 0x64f98fa7;
	ctx->h = 0xbefa4fa4;

	ctx->bit_len = 0;
	ft_bzero(ctx->block, FT_SHA256_BLOCK_SIZE);
}