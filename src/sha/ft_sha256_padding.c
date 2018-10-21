#include "ft_sha.h"
#include "libft.h"

void ft_sha256_padding(BYTE1 padding[FT_SHA256_BLOCK_SIZE])
{
	padding[0] = 0x80;
	ft_bzero(&padding[1], FT_SHA256_BLOCK_SIZE - 1);
}