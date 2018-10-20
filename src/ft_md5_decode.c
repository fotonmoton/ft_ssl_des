#include "ft_md5.h"

void ft_md5_decode(BYTE4 w[FT_MD5_WORDS_COUNT], BYTE1 b[FT_MD5_BLOCK_SIZE])
{
    BYTE8 i;
    BYTE8 j;

    i = 0;
    j = 0;

    while (j < FT_MD5_BLOCK_SIZE)
    {
        w[i] =  ((BYTE4)b[j])               |
                (((BYTE4)b[j + 1]) << 8)    |
                (((BYTE4)b[j + 2]) << 16)   |
                (((BYTE4)b[j + 3]) << 24);
        i++;
        j += 4;
    }
}