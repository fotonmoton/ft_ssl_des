#include "ft_sha.h"

void ft_sha224_update(t_sha256_ctx *ctx, BYTE1 *message, BYTE8 len)
{
	ft_sha256_update(ctx, message, len);
}