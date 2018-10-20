#ifndef FT_MD5_H
# define FT_MD5_H

# include <stdint.h>

# define FT_MD5_BLOCK_SIZE 64
# define FT_MD5_WORDS_COUNT 16
# define FT_MD5_MESSAGE_LENGTH_BYTE 8
# define FT_MD5_DIGEST_LENGTH_BYTE 16
# define FT_MD5_STRING_SIZE_BYTE 33

# define S11 7
# define S12 12
# define S13 17
# define S14 22
# define S21 5
# define S22 9
# define S23 14
# define S24 20
# define S31 4
# define S32 11
# define S33 16
# define S34 23
# define S41 6
# define S42 10
# define S43 15
# define S44 21

/* F, G, H and I are basic MD5 functions.
 */
# define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
# define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
# define H(x, y, z) ((x) ^ (y) ^ (z))
# define I(x, y, z) ((y) ^ ((x) | (~z)))

/* ROTATE_LEFT rotates x left n bits.
 */
# define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

/* FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
Rotation is separate from addition to prevent recomputation.
 */
# define FF(a, b, c, d, x, s, ac)                    \
    {                                                \
        (a) += F((b), (c), (d)) + (x) + (BYTE4)(ac); \
        (a) = ROTATE_LEFT((a), (s));                 \
        (a) += (b);                                  \
    }

# define GG(a, b, c, d, x, s, ac)                    \
    {                                                \
        (a) += G((b), (c), (d)) + (x) + (BYTE4)(ac); \
        (a) = ROTATE_LEFT((a), (s));                 \
        (a) += (b);                                  \
    }

# define HH(a, b, c, d, x, s, ac)                    \
    {                                                \
        (a) += H((b), (c), (d)) + (x) + (BYTE4)(ac); \
        (a) = ROTATE_LEFT((a), (s));                 \
        (a) += (b);                                  \
    }

# define II(a, b, c, d, x, s, ac)                    \
    {                                                \
        (a) += I((b), (c), (d)) + (x) + (BYTE4)(ac); \
        (a) = ROTATE_LEFT((a), (s));                 \
        (a) += (b);                                  \
    }

typedef uint64_t BYTE8;
typedef uint32_t BYTE4;
typedef unsigned char BYTE1;

typedef struct  s_md5_ctx
{
	BYTE4       a;
	BYTE4       b;
	BYTE4       c;
	BYTE4       d;
	BYTE1       block[FT_MD5_BLOCK_SIZE];
	BYTE8       bit_len;
}               t_md5_ctx;

void            ft_md5_init(t_md5_ctx *ctx);
void            ft_md5_update(t_md5_ctx *ctx, BYTE1 *chunk, BYTE8 len);
void            ft_md5_transform(t_md5_ctx *ctx, BYTE1 blck[FT_MD5_BLOCK_SIZE]);
void            ft_md5_final(BYTE1 digest[FT_MD5_DIGEST_LENGTH_BYTE],
					t_md5_ctx *ctx);
void			ft_md5_decode(BYTE4 w[FT_MD5_WORDS_COUNT],
					BYTE1 b[FT_MD5_BLOCK_SIZE]);
void            ft_md5_encode_len(BYTE1 bits[FT_MD5_MESSAGE_LENGTH_BYTE],
					BYTE8 bit_len);
void			ft_md5_encode_register(BYTE1 *digest_part, BYTE4 reg);
void			ft_md5_padding(BYTE1 padding[FT_MD5_BLOCK_SIZE]);
void			ft_md5_digest_string(BYTE1 digest[FT_MD5_DIGEST_LENGTH_BYTE],
					BYTE1 string[FT_MD5_STRING_SIZE_BYTE]);
void			ft_md5_string(BYTE1 *str);
void 			ft_md5_file(BYTE1 *filename);
void            ft_md5_filter(void);

#endif
