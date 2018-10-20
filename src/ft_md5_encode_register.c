#include "ft_md5.h"

void ft_md5_encode_register(BYTE1 *digest_part, BYTE4 reg)
{
	digest_part[0] = (BYTE1)(reg & 0xff);
	digest_part[1] = (BYTE1)(reg >> 8 & 0xff);
	digest_part[2] = (BYTE1)(reg >> 16 & 0xff);
	digest_part[3] = (BYTE1)(reg >> 24 & 0xff);
}