#include "ft_md5.h"

void ft_md5_encode_len(BYTE1 bits[FT_MD5_MESSAGE_LENGTH_BYTE], BYTE8 len)
{
	bits[0] = (BYTE1)(len & 0xff);
	bits[1] = (BYTE1)(len >> 8 & 0xff);
	bits[2] = (BYTE1)(len >> 16 & 0xff);
	bits[3] = (BYTE1)(len >> 24 & 0xff);
	bits[4] = (BYTE1)(len >> 32 & 0xff);
	bits[5] = (BYTE1)(len >> 40 & 0xff);
	bits[6] = (BYTE1)(len >> 48 & 0xff);
	bits[7] = (BYTE1)(len >> 56 & 0xff);
}