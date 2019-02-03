/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:20:23 by gtertysh          #+#    #+#             */
/*   Updated: 2019/02/03 18:41:48 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA_H
# define FT_SHA_H

# include <stdint.h>

# define FT_SHA256_READ_BLOCK_SIZE 1024
# define FT_SHA256_BLOCK_SIZE 64
# define FT_SHA256_WORDS_COUNT 16
# define FT_SHA256_MESSAGE_LENGTH_BYTE 8
# define FT_SHA256_DIGEST_LENGTH_BYTE 32
# define FT_SHA256_STRING_SIZE_BYTE 65
# define FT_SHA256_REG_SIZE_BYTE 4

# define FT_SHA224_DIGEST_LENGTH_BYTE 28
# define FT_SHA224_STRING_SIZE_BYTE 57

# define SHR(bits, word) ((word) >> (bits))
# define ROTL(bits, word) (((word) << (bits)) | ((word) >> (32 - (bits))))
# define ROTR(bits, word) (((word) >> (bits)) | ((word) << (32 - (bits))))

# define SHA256_SIGMA0(w) (ROTR(2, w) ^ ROTR(13, w) ^ ROTR(22, w))
# define SHA256_SIGMA1(word) (ROTR(6, word) ^ ROTR(11, word) ^ ROTR(25, word))
# define SHA256_SIG0(word) (ROTR(7, word) ^ ROTR(18, word) ^ SHR(3, word))
# define SHA256_SIG1(word) (ROTR(17, word) ^ ROTR(19, word) ^ SHR(10, word))

# define SHA_CH(x, y, z) (((x) & ((y) ^ (z))) ^ (z))
# define SHA_MAJ(x, y, z) (((x) & ((y) | (z))) | ((y) & (z)))

typedef uint64_t		t_byte8;
typedef uint32_t		t_byte4;
typedef unsigned char	t_byte1;

typedef struct			s_sha256_ctx
{
	t_byte4				a;
	t_byte4				b;
	t_byte4				c;
	t_byte4				d;
	t_byte4				e;
	t_byte4				f;
	t_byte4				g;
	t_byte4				h;
	t_byte1				block[FT_SHA256_BLOCK_SIZE];
	t_byte8				bit_len;
}						t_sha256_ctx;

typedef struct			s_temp_registers
{
	t_byte4				a;
	t_byte4				b;
	t_byte4				c;
	t_byte4				d;
	t_byte4				e;
	t_byte4				f;
	t_byte4				g;
	t_byte4				h;
}						t_temp_registers;

typedef struct			s_sha_flags
{
	int					quiet;
	int					reverse;
	int					print_stdin;
	int					something_printed;
}						t_sha_flags;

void					ft_sha256
(
						int argc,
						char **argv
);

void					ft_sha256_string
(
						t_sha256_ctx *ctx,
						t_byte1 *message,
						t_sha_flags *flags
);

void					ft_sha256_file
(
						t_sha256_ctx *ctx,
						t_byte1 *filename,
						t_sha_flags *flags
);

void					ft_sha256_stdin
(
						t_sha256_ctx *ctx,
						t_sha_flags *flags
);

void					ft_sha256_init
(
						t_sha256_ctx *ctx
);

void					ft_sha256_update
(
						t_sha256_ctx *ctx,
						t_byte1 *message,
						t_byte8 len
);

void					ft_sha256_final
(
						t_byte1 digest[FT_SHA256_DIGEST_LENGTH_BYTE],
						t_sha256_ctx *ctx
);

void					ft_sha256_transform
(
						t_sha256_ctx *ctx,
						t_byte1 block[FT_SHA256_BLOCK_SIZE]
);

void					ft_sha256_decode
(
						t_byte4 w[FT_SHA256_WORDS_COUNT],
						t_byte1 b[FT_SHA256_BLOCK_SIZE]
);

void					ft_sha256_encode_len
(
						t_byte1 b[FT_SHA256_MESSAGE_LENGTH_BYTE],
						t_byte8 len
);

void					ft_sha256_encode_register
(
						t_byte1 digest_part[FT_SHA256_REG_SIZE_BYTE],
						t_byte4 reg
);

void					ft_sha256_padding
(
						t_byte1 padding[FT_SHA256_BLOCK_SIZE]
);

void					ft_sha256_digest_string
(
						t_byte1 digest[FT_SHA256_DIGEST_LENGTH_BYTE],
						t_byte1 digst_string[FT_SHA256_STRING_SIZE_BYTE]
);

t_byte4					*ft_sha256_constants(void);

void					ft_sha224
(
						int argc,
						char **argv
);

void					ft_sha224_string
(
						t_sha256_ctx *ctx,
						t_byte1 *message,
						t_sha_flags *flags
);

void					ft_sha224_file
(
						t_sha256_ctx *ctx,
						t_byte1 *filename,
						t_sha_flags *flags
);

void					ft_sha224_stdin
(
						t_sha256_ctx *ctx,
						t_sha_flags *flags
);

void					ft_sha224_init
(
						t_sha256_ctx *ctx
);

void					ft_sha224_update
(
						t_sha256_ctx *ctx,
						t_byte1 *message,
						t_byte8 len
);

void					ft_sha224_final
(
						t_byte1 digest[FT_SHA256_DIGEST_LENGTH_BYTE],
						t_sha256_ctx *ctx
);

void					ft_sha224_digest_string
(
						t_byte1 digest[FT_SHA224_DIGEST_LENGTH_BYTE],
						t_byte1 digst_string[FT_SHA224_STRING_SIZE_BYTE]
);

void					ft_sha_usage
(
						const char *alorithm
);

void					ft_sha_print
(
						const char *algorithm,
						t_byte1 *message,
						t_byte1 *digest,
						t_sha_flags *flags
);

#endif
