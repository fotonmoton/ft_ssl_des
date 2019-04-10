/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pbkdf2.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:56:11 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 15:56:16 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PBKDF2_H
# define FT_PBKDF2_H

# include "ft_sha.h"

typedef struct		s_pbkdf2_sha256_ctx
{
	unsigned char	*pass;
	unsigned char	*salt;
	unsigned char	*key;
	unsigned int	key_len;
	unsigned int	pass_len;
	unsigned int	salt_len;
	unsigned int	iterations;
}					t_pbkdf2_sha256_ctx;

typedef struct		s_hmac_sha256_ctx
{
	unsigned char	*key;
	unsigned char	*msg;
	unsigned int	key_size;
	unsigned int	msg_size;
	unsigned char	ipad[FT_SHA256_BLOCK_SIZE];
	unsigned char	opad[FT_SHA256_BLOCK_SIZE];
	t_sha256_ctx	sha_ctx;
}					t_hmac_sha256_ctx;

void				ft_hmac_sha256_init_ctx
(
	t_hmac_sha256_ctx *ctx
);

void				ft_hmac_sha256
(
	t_hmac_sha256_ctx *ctx,
	unsigned char out[FT_SHA256_DIGEST_LENGTH_BYTE]
);

void				ft_hmac_sha256_start
(
	t_hmac_sha256_ctx *ctx
);

void				ft_hmac_sha256_update
(
	t_hmac_sha256_ctx *ctx,
	unsigned char *msg,
	unsigned int msg_size
);

void				ft_hmac_sha256_finish
(
	t_hmac_sha256_ctx *ctx,
	unsigned char out[FT_SHA256_DIGEST_LENGTH_BYTE]
);

void				ft_pbkdf2_sha256_init_ctx
(
	t_pbkdf2_sha256_ctx *ctx
);

void				ft_pbkdf2_sha256
(
	t_pbkdf2_sha256_ctx *ctx
);

#endif
