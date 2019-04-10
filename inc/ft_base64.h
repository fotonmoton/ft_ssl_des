/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:58:39 by gtertysh          #+#    #+#             */
/*   Updated: 2019/01/19 17:59:19 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE64_H
# define FT_BASE64_H

# include <stdint.h>

# define FT_BASE64_READ_SIZE 1024
# define FT_BASE64_ENCODE_BLOCK_SIZE 3
# define FT_BASE64_DECODE_BLOCK_SIZE 4
# define FT_BASE64_ALPHABET_LENGTH 65

typedef uint64_t		t_byte8;
typedef unsigned char	t_byte1;

typedef struct			s_base64_encode_buffer
{
	t_byte1				block[FT_BASE64_ENCODE_BLOCK_SIZE];
	t_byte8				readed;
}						t_base64_encode_buffer;

typedef struct			s_base64_decode_buffer
{
	t_byte1				block[FT_BASE64_DECODE_BLOCK_SIZE];
	t_byte8				readed;
}						t_base64_decode_buffer;

typedef struct			s_base64_ctx
{
	int					input_fd;
	int					output_fd;
	t_byte1				alphabet[FT_BASE64_ALPHABET_LENGTH];
}						t_base64_ctx;

typedef struct			s_base64_flags
{
	int					decode;
}						t_base64_flags;

void					ft_base64
(
	int argc,
	char **argv
);

void					ft_base64_init
(
	t_base64_ctx *ctx
);

void					ft_base64_decode
(
	t_base64_ctx *ctx
);

void					ft_base64_encode
(
	t_base64_ctx *ctx
);

t_byte8					ft_base64_encode_step
(
	t_base64_ctx *ctx,
	t_byte1 *buff
);

void					ft_base64_encode_finish
(

	t_base64_ctx *ctx,
	t_base64_encode_buffer *buff
);

void					ft_base64_fill_buffer
(
	t_base64_ctx *ctx,
	t_byte1 *data,
	t_byte8 size
);

void					ft_base64_encode_transform
(
	t_base64_ctx *ctx,
	t_byte1 data[FT_BASE64_ENCODE_BLOCK_SIZE],
	t_byte1 chars[FT_BASE64_DECODE_BLOCK_SIZE]
);

void					ft_base64_encode_chunk
(
	t_base64_ctx *ctx,
	t_byte8 len,
	t_byte1 *message,
	t_base64_encode_buffer *enc_buff
);

void					ft_base64_init_encode_buffer
(
	t_base64_encode_buffer *buff
);

void					ft_base64_init_decode_buffer
(
	t_base64_decode_buffer *buff
);

void					ft_base64_decode_chunk
(
	t_base64_ctx *ctx,
	t_byte8 len,
	t_byte1 *message,
	t_base64_decode_buffer *dec_buff
);

void					ft_base64_decode_transform
(
	t_base64_ctx *ctx,
	t_byte1 *message,
	t_byte1 decoded_block[FT_BASE64_ENCODE_BLOCK_SIZE]
);

void					ft_base64_decode_finish
(
	t_base64_decode_buffer *buff
);

t_byte8					ft_base64_decode_filter
(
	t_byte8 readed,
	t_byte1 *buff
);

#endif
