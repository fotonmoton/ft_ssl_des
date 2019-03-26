#include "ft_pbkdf2.h"
#include "libft.h"

static void	set_padding
(
	unsigned char ipad[FT_SHA256_BLOCK_SIZE],
	unsigned char opad[FT_SHA256_BLOCK_SIZE],
	unsigned char key[FT_SHA256_BLOCK_SIZE]
)
{
	int i;

	i = 0;
	while(i < FT_SHA256_BLOCK_SIZE)
	{
		ipad[i] = key[i] ^ 0x36;
		opad[i] = key[i] ^ 0x5c;
		i++;
	}
}

static void	finish
(
	t_hmac_sha256_ctx *ctx,
	t_sha256_ctx *sha256_ctx,
	unsigned char ipad[FT_SHA256_BLOCK_SIZE],
	unsigned char opad[FT_SHA256_BLOCK_SIZE]
)
{
	ft_sha256_init(sha256_ctx);
	ft_sha256_update(sha256_ctx, ipad, FT_SHA256_BLOCK_SIZE);
	ft_sha256_update(sha256_ctx, ctx->msg, ctx->msg_size);
	ft_sha256_final(ctx->out, sha256_ctx);
	ft_sha256_init(sha256_ctx);
	ft_sha256_update(sha256_ctx, opad, FT_SHA256_BLOCK_SIZE);
	ft_sha256_update(sha256_ctx, ctx->out, FT_SHA256_DIGEST_LENGTH_BYTE);
	ft_sha256_final(ctx->out, sha256_ctx);
}

void		ft_hmac_sha256
(
	t_hmac_sha256_ctx *ctx
)
{
	t_sha256_ctx sha256_ctx;
	unsigned char key[FT_SHA256_BLOCK_SIZE];
	unsigned char ipad[FT_SHA256_BLOCK_SIZE];
	unsigned char opad[FT_SHA256_BLOCK_SIZE];

	ft_bzero(key, FT_SHA256_BLOCK_SIZE);
	if (ctx->key_size > FT_SHA256_BLOCK_SIZE)
	{
		ft_sha256_init(&sha256_ctx);
		ft_sha256_update(&sha256_ctx, ctx->key, ctx->key_size);
		ft_sha256_final(key, &sha256_ctx);
	}
	else
		ft_memcpy(key, ctx->key, ctx->key_size);
	set_padding(ipad, opad, key);
	finish(ctx, &sha256_ctx, ipad, opad);
}