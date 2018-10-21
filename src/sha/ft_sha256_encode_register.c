#include "ft_sha.h"

void ft_sha256_encode_register
(
	BYTE1 digest_part[FT_SHA256_REG_SIZE_BYTE],
	BYTE4 reg
)
{
	digest_part[0] = reg >> 24 & 0xff;
	digest_part[1] = reg >> 16 & 0xff;
	digest_part[2] = reg >> 8 & 0xff;
	digest_part[3] = reg & 0xff;
}