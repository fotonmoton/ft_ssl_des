#include "ft_pbkdf2.h"
#include "libft.h"
#include "ft_sha.h"

static void	set_padding
(
	t_hmac_sha256_ctx *ctx,
	unsigned char key[FT_SHA256_BLOCK_SIZE]
)
{
	int i;

	i = 0;
	while(i < FT_SHA256_BLOCK_SIZE)
	{
		ctx->ipad[i] = key[i] ^ 0x36;
		ctx->opad[i] = key[i] ^ 0x5c;
		i++;
	}
}

void	ft_hmac_sha256_finish
(
	t_hmac_sha256_ctx *ctx,
	unsigned char out[FT_SHA256_DIGEST_LENGTH_BYTE]
)
{
	ft_sha256_final(out, &ctx->sha_ctx);
	ft_sha256_init(&ctx->sha_ctx);
	ft_sha256_update(&ctx->sha_ctx, ctx->opad, FT_SHA256_BLOCK_SIZE);
	ft_sha256_update(&ctx->sha_ctx, out, FT_SHA256_DIGEST_LENGTH_BYTE);
	ft_sha256_final(out, &ctx->sha_ctx);
}

void		ft_hmac_sha256_start
(
	t_hmac_sha256_ctx *ctx
)
{
	unsigned char key[FT_SHA256_BLOCK_SIZE];

	ft_bzero(key, FT_SHA256_BLOCK_SIZE);
	if (ctx->key_size > FT_SHA256_BLOCK_SIZE)
	{
		ft_sha256_init(&ctx->sha_ctx);
		ft_sha256_update(&ctx->sha_ctx, ctx->key, ctx->key_size);
		ft_sha256_final(key, &ctx->sha_ctx);
	}
	else
		ft_memcpy(key, ctx->key, ctx->key_size);
	set_padding(ctx, key);
	ft_sha256_init(&ctx->sha_ctx);
	ft_sha256_update(&ctx->sha_ctx, ctx->ipad, FT_SHA256_BLOCK_SIZE);
}

void		ft_hmac_sha256_update
(
	t_hmac_sha256_ctx *ctx,
	unsigned char *msg,
	unsigned int msg_size
)
{
	ft_sha256_update(&ctx->sha_ctx, msg, msg_size);
}

void		ft_hmac_sha256
(
	t_hmac_sha256_ctx *ctx,
	unsigned char out[FT_SHA256_DIGEST_LENGTH_BYTE]
)
{
	ft_hmac_sha256_start(ctx);
	ft_hmac_sha256_update(ctx, ctx->msg, ctx->msg_size);
	ft_hmac_sha256_finish(ctx, out);
}