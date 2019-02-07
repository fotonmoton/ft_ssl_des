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

# define FT_BASE64_GLUE_BLOCK_SIZE 3
# define FT_BASE64_CHARS_SIZE 4
# define FT_BASE64_ALPHABET_LENGTH 64

typedef uint64_t		t_byte8;
typedef unsigned char	t_byte1;

typedef struct			s_base64_ctx
{
	int					input_fd;
	int					output_fd;
	t_byte8				glue_block_bytes_count;
	t_byte1				glue_block[FT_BASE64_GLUE_BLOCK_SIZE];
	t_byte1				alphabet[FT_BASE64_ALPHABET_LENGTH];
	t_byte1				chars[FT_BASE64_CHARS_SIZE];
}						t_base64_ctx;

typedef struct 			s_base64_flags
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

void					ft_base64_fill_buffer
(
	t_base64_ctx *ctx,
	t_byte1 *data,
	t_byte8 size
);

void					ft_base64_transform
(
	t_base64_ctx *ctx,
	t_byte1 *data
);

#endif
