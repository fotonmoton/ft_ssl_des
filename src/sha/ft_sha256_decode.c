#include "ft_sha.h"

void ft_sha256_decode
(
	BYTE4 w[FT_SHA256_WORDS_COUNT],
	BYTE1 b[FT_SHA256_BLOCK_SIZE]
)
{
	BYTE8 i;
	BYTE8 j;

	i = 0;
	j = 0;

	while (i < FT_SHA256_WORDS_COUNT)
	{
		w[i] = ((((BYTE4)b[j]) << 24)		|
				(((BYTE4)b[j + 1]) << 16)	|
				(((BYTE4)b[j + 2]) << 8)	|
				((BYTE4)b[j + 3]));
		i++;
		j += 4;
	}
}