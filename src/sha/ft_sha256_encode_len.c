#include "ft_sha.h"

void ft_sha256_encode_len(BYTE1 b[FT_SHA256_MESSAGE_LENGTH_BYTE], BYTE8 len)
{
	b[7] = (BYTE1)(len & 0xff);
	b[6] = (BYTE1)(len >> 8 & 0xff);
	b[5] = (BYTE1)(len >> 16 & 0xff);
	b[4] = (BYTE1)(len >> 24 & 0xff);
	b[3] = (BYTE1)(len >> 32 & 0xff);
	b[2] = (BYTE1)(len >> 40 & 0xff);
	b[1] = (BYTE1)(len >> 48 & 0xff);
	b[0] = (BYTE1)(len >> 56 & 0xff);
}