#include "ft_sha.h"

void ft_sha224_final
(
	BYTE1 digest[FT_SHA256_DIGEST_LENGTH_BYTE],
	t_sha256_ctx *ctx
)
{
	ft_sha256_final(digest, ctx);
}