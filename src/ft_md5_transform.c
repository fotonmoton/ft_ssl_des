#include "ft_md5.h"
#include "libft.h"

void	ft_md5_transform(t_md5_ctx *ctx, BYTE1 block[FT_MD5_BLOCK_SIZE])
{
    BYTE4 words[FT_MD5_WORDS_COUNT];
    BYTE4 a;
    BYTE4 b;
    BYTE4 c;
    BYTE4 d;

    a = ctx->a;
    b = ctx->b;
    c = ctx->c;
    d = ctx->d;

    ft_md5_decode(words, block);

    /* Round 1 */
    FF(a, b, c, d, words[0], S11, 0xd76aa478);  /* 1 */
    FF(d, a, b, c, words[1], S12, 0xe8c7b756);  /* 2 */
    FF(c, d, a, b, words[2], S13, 0x242070db);  /* 3 */
    FF(b, c, d, a, words[3], S14, 0xc1bdceee);  /* 4 */
    FF(a, b, c, d, words[4], S11, 0xf57c0faf);  /* 5 */
    FF(d, a, b, c, words[5], S12, 0x4787c62a);  /* 6 */
    FF(c, d, a, b, words[6], S13, 0xa8304613);  /* 7 */
    FF(b, c, d, a, words[7], S14, 0xfd469501);  /* 8 */
    FF(a, b, c, d, words[8], S11, 0x698098d8);  /* 9 */
    FF(d, a, b, c, words[9], S12, 0x8b44f7af);  /* 10 */
    FF(c, d, a, b, words[10], S13, 0xffff5bb1); /* 11 */
    FF(b, c, d, a, words[11], S14, 0x895cd7be); /* 12 */
    FF(a, b, c, d, words[12], S11, 0x6b901122); /* 13 */
    FF(d, a, b, c, words[13], S12, 0xfd987193); /* 14 */
    FF(c, d, a, b, words[14], S13, 0xa679438e); /* 15 */
    FF(b, c, d, a, words[15], S14, 0x49b40821); /* 16 */

    /* Round 2 */
    GG(a, b, c, d, words[1], S21, 0xf61e2562);  /* 17 */
    GG(d, a, b, c, words[6], S22, 0xc040b340);  /* 18 */
    GG(c, d, a, b, words[11], S23, 0x265e5a51); /* 19 */
    GG(b, c, d, a, words[0], S24, 0xe9b6c7aa);  /* 20 */
    GG(a, b, c, d, words[5], S21, 0xd62f105d);  /* 21 */
    GG(d, a, b, c, words[10], S22, 0x2441453);  /* 22 */
    GG(c, d, a, b, words[15], S23, 0xd8a1e681); /* 23 */
    GG(b, c, d, a, words[4], S24, 0xe7d3fbc8);  /* 24 */
    GG(a, b, c, d, words[9], S21, 0x21e1cde6);  /* 25 */
    GG(d, a, b, c, words[14], S22, 0xc33707d6); /* 26 */
    GG(c, d, a, b, words[3], S23, 0xf4d50d87);  /* 27 */
    GG(b, c, d, a, words[8], S24, 0x455a14ed);  /* 28 */
    GG(a, b, c, d, words[13], S21, 0xa9e3e905); /* 29 */
    GG(d, a, b, c, words[2], S22, 0xfcefa3f8);  /* 30 */
    GG(c, d, a, b, words[7], S23, 0x676f02d9);  /* 31 */
    GG(b, c, d, a, words[12], S24, 0x8d2a4c8a); /* 32 */

    /* Round 3 */
    HH(a, b, c, d, words[5], S31, 0xfffa3942);  /* 33 */
    HH(d, a, b, c, words[8], S32, 0x8771f681);  /* 34 */
    HH(c, d, a, b, words[11], S33, 0x6d9d6122); /* 35 */
    HH(b, c, d, a, words[14], S34, 0xfde5380c); /* 36 */
    HH(a, b, c, d, words[1], S31, 0xa4beea44);  /* 37 */
    HH(d, a, b, c, words[4], S32, 0x4bdecfa9);  /* 38 */
    HH(c, d, a, b, words[7], S33, 0xf6bb4b60);  /* 39 */
    HH(b, c, d, a, words[10], S34, 0xbebfbc70); /* 40 */
    HH(a, b, c, d, words[13], S31, 0x289b7ec6); /* 41 */
    HH(d, a, b, c, words[0], S32, 0xeaa127fa);  /* 42 */
    HH(c, d, a, b, words[3], S33, 0xd4ef3085);  /* 43 */
    HH(b, c, d, a, words[6], S34, 0x4881d05);   /* 44 */
    HH(a, b, c, d, words[9], S31, 0xd9d4d039);  /* 45 */
    HH(d, a, b, c, words[12], S32, 0xe6db99e5); /* 46 */
    HH(c, d, a, b, words[15], S33, 0x1fa27cf8); /* 47 */
    HH(b, c, d, a, words[2], S34, 0xc4ac5665);  /* 48 */

    /* Round 4 */
    II(a, b, c, d, words[0], S41, 0xf4292244);  /* 49 */
    II(d, a, b, c, words[7], S42, 0x432aff97);  /* 50 */
    II(c, d, a, b, words[14], S43, 0xab9423a7); /* 51 */
    II(b, c, d, a, words[5], S44, 0xfc93a039);  /* 52 */
    II(a, b, c, d, words[12], S41, 0x655b59c3); /* 53 */
    II(d, a, b, c, words[3], S42, 0x8f0ccc92);  /* 54 */
    II(c, d, a, b, words[10], S43, 0xffeff47d); /* 55 */
    II(b, c, d, a, words[1], S44, 0x85845dd1);  /* 56 */
    II(a, b, c, d, words[8], S41, 0x6fa87e4f);  /* 57 */
    II(d, a, b, c, words[15], S42, 0xfe2ce6e0); /* 58 */
    II(c, d, a, b, words[6], S43, 0xa3014314);  /* 59 */
    II(b, c, d, a, words[13], S44, 0x4e0811a1); /* 60 */
    II(a, b, c, d, words[4], S41, 0xf7537e82);  /* 61 */
    II(d, a, b, c, words[11], S42, 0xbd3af235); /* 62 */
    II(c, d, a, b, words[2], S43, 0x2ad7d2bb);  /* 63 */
    II(b, c, d, a, words[9], S44, 0xeb86d391);  /* 64 */

    ctx->a += a;
    ctx->b += b;
    ctx->c += c;
    ctx->d += d;
    /* Zeroize sensitive information.*/
    ft_bzero(words, sizeof(words));
}