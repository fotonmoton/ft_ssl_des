#ifndef FT_SHA_H
# define FT_SHA_H

#include <stdint.h>

# define FT_SHA256_BLOCK_SIZE 64
# define FT_SHA256_WORDS_COUNT 16
# define FT_SHA256_MESSAGE_LENGTH_BYTE 8
# define FT_SHA256_DIGEST_LENGTH_BYTE 32
# define FT_SHA256_STRING_SIZE_BYTE 65
# define FT_SHA256_REG_SIZE_BYTE 4

/* Define the SHA shift, rotate left, and rotate right macros */
#define SHR(bits, word) ((word) >> (bits))
#define ROTL(bits, word) (((word) << (bits)) | ((word) >> (32 - (bits))))
#define ROTR(bits, word) (((word) >> (bits)) | ((word) << (32 - (bits))))

/* Define the SHA SIGMA and sigma macros */
#define SHA256_SIGMA0(w) (ROTR(2, w) ^ ROTR(13, w) ^ ROTR(22, w))
#define SHA256_SIGMA1(word) (ROTR(6, word) ^ ROTR(11, word) ^ ROTR(25, word))
#define SHA256_sigma0(word) (ROTR(7, word) ^ ROTR(18, word) ^ SHR(3, word))
#define SHA256_sigma1(word) (ROTR(17, word) ^ ROTR(19, word) ^ SHR(10, word))

#define SHA_Ch(x, y, z) (((x) & ((y) ^ (z))) ^ (z))
#define SHA_Maj(x, y, z) (((x) & ((y) | (z))) | ((y) & (z)))

typedef uint64_t	BYTE8;
typedef uint32_t	BYTE4;
typedef unsigned	char BYTE1;

typedef struct 		s_sha256_ctx
{
	BYTE4			a;
	BYTE4			b;
	BYTE4			c;
	BYTE4			d;
	BYTE4			e;
	BYTE4			f;
	BYTE4			g;
	BYTE4			h;
	BYTE1 			block[FT_SHA256_BLOCK_SIZE];
	BYTE8			bit_len;
}					t_sha256_ctx;

typedef struct 		s_temp_registers
{
	BYTE4			a;
	BYTE4			b;
	BYTE4			c;
	BYTE4			d;
	BYTE4			e;
	BYTE4			f;
	BYTE4			g;
	BYTE4			h;
}					t_temp_registers;

void				ft_sha256_init(t_sha256_ctx *ctx);
void 				ft_sha256_update(t_sha256_ctx *ctx,
						BYTE1 *message, BYTE8 len);
void				ft_sha256_final(BYTE1 digest[FT_SHA256_DIGEST_LENGTH_BYTE],
						t_sha256_ctx *ctx);
void				ft_sha256_transform(t_sha256_ctx *ctx,
						BYTE1 block[FT_SHA256_BLOCK_SIZE]);
void 				ft_sha256_decode(BYTE4 w[FT_SHA256_WORDS_COUNT],
						BYTE1 b[FT_SHA256_BLOCK_SIZE]);
void				ft_sha256_encode_len(BYTE1 b[FT_SHA256_MESSAGE_LENGTH_BYTE],
						BYTE8 len);
void				ft_sha256_encode_register(
						BYTE1 digest_part[FT_SHA256_REG_SIZE_BYTE], BYTE4 reg);
void				ft_sha256_padding(BYTE1 padding[FT_SHA256_BLOCK_SIZE]);
void				ft_sha256_digest_string(
						BYTE1 digest[FT_SHA256_DIGEST_LENGTH_BYTE],
						BYTE1 digst_string[FT_SHA256_STRING_SIZE_BYTE]);
BYTE4				*ft_sha256_constants(void);

#endif