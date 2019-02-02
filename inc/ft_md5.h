/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:11:58 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 19:12:43 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include <stdint.h>

# define FT_MD5_READ_BLOCK_SIZE 1024
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

# define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
# define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
# define H(x, y, z) ((x) ^ (y) ^ (z))
# define I(x, y, z) ((y) ^ ((x) | (~z)))

# define RL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

# define FF1(a, b, c, d, x, ac) (a) += F((b), (c), (d)) + (x) + (t_byte4)(ac)
# define FF2(a, s) (a) = RL((a), (s))
# define FF3(a, b) (a) += (b)

# define FF(a, b, c, d, x, s, ac) FF1(a, b, c, d, x, ac); FF2(a, s); FF3(a, b);

# define GG1(a, b, c, d, x, ac) (a) += G((b), (c), (d)) + (x) + (t_byte4)(ac)
# define GG2(a, s) (a) = RL((a), (s))
# define GG3(a, b) (a) += (b)

# define GG(a, b, c, d, x, s, ac) GG1(a, b, c, d, x, ac); GG2(a, s); GG3(a, b);

# define HH1(a, b, c, d, x, ac) (a) += H((b), (c), (d)) + (x) + (t_byte4)(ac)
# define HH2(a, s) (a) = RL((a), (s))
# define HH3(a, b) (a) += (b)

# define HH(a, b, c, d, x, s, ac) HH1(a, b, c, d, x, ac); HH2(a, s); HH3(a, b);

# define II1(a, b, c, d, x, ac) (a) += I((b), (c), (d)) + (x) + (t_byte4)(ac)
# define II2(a, s) (a) = RL((a), (s))
# define II3(a, b) (a) += (b)

# define II(a, b, c, d, x, s, ac) II1(a, b, c, d, x, ac); II2(a, s); II3(a, b);

typedef uint64_t		t_byte8;
typedef uint32_t		t_byte4;
typedef unsigned char	t_byte1;

typedef struct			s_md5_ctx
{
	t_byte4				a;
	t_byte4				b;
	t_byte4				c;
	t_byte4				d;
	t_byte1				block[FT_MD5_BLOCK_SIZE];
	t_byte8				bit_len;
}						t_md5_ctx;

typedef struct			s_md5_intr_registers
{
	t_byte4				a;
	t_byte4				b;
	t_byte4				c;
	t_byte4				d;
}						t_md5_intr_registers;

typedef struct			s_md5_flags
{
	int					quiet;
	int					reverse;
	int					print_stdin;
	int					something_printed;
}						t_md5_flags;

void					ft_md5
(
						int argc,
						char **argv
);

void					ft_md5_init
(
						t_md5_ctx *ctx
);

void					ft_md5_update
(
						t_md5_ctx *ctx, t_byte1 *chunk,
						t_byte8 len
);

void					ft_md5_transform
(
						t_md5_ctx *ctx,
						t_byte1 blck[FT_MD5_BLOCK_SIZE]
);
void					ft_md5_final
(
						t_byte1 digest[FT_MD5_DIGEST_LENGTH_BYTE],
						t_md5_ctx *ctx
);

void					ft_md5_decode
(
						t_byte4 w[FT_MD5_WORDS_COUNT],
						t_byte1 b[FT_MD5_BLOCK_SIZE]
);

void					ft_md5_encode_len
(
						t_byte1 bits[FT_MD5_MESSAGE_LENGTH_BYTE],
						t_byte8 bit_len
);

void					ft_md5_encode_register
(
						t_byte1 *digest_part,
						t_byte4 reg
);

void					ft_md5_padding
(
						t_byte1 padding[FT_MD5_BLOCK_SIZE]
);

void					ft_md5_digest_string
(
						t_byte1 digest[FT_MD5_DIGEST_LENGTH_BYTE],
						t_byte1 string[FT_MD5_STRING_SIZE_BYTE]
);

void					ft_md5_string
(
						const char *message,
						t_md5_flags *flags
);

void					ft_md5_file
(
						const char *filename,
						t_md5_flags *flags
);

void					ft_md5_stdin
(
						t_md5_flags *flags
);

void					ft_md5_print
(
						t_byte1 *message,
						t_byte1 *digest,
						t_md5_flags *flags
);

#endif
