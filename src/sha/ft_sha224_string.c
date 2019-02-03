/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha224_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:32:29 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:32:48 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void	ft_sha224_string(
	t_sha256_ctx *ctx,
	t_byte1 *message,
	t_sha_flags *flags
)
{
	t_byte1			digest[FT_SHA224_DIGEST_LENGTH_BYTE];
	t_byte1			digest_string[FT_SHA224_STRING_SIZE_BYTE];

	ft_sha224_init(ctx);
	ft_sha224_update(ctx, message, ft_strlen((const char *)message));
	ft_sha224_final(digest, ctx);
	ft_sha224_digest_string(digest, digest_string);
	ft_sha_print("SHA224", message, digest_string, flags);
}
