/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha224_stdin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:31:54 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:32:14 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void	ft_sha224_stdin(t_sha256_ctx *ctx, t_sha_flags *flags)
{
	int				len;
	t_byte1			buf[FT_SHA256_READ_BLOCK_SIZE];
	t_byte1			digest[FT_SHA224_DIGEST_LENGTH_BYTE];
	t_byte1			digest_string[FT_SHA224_STRING_SIZE_BYTE];

	ft_sha224_init(ctx);
	while ((len = read(0, buf, FT_SHA256_READ_BLOCK_SIZE)))
	{
		if (flags->print_stdin)
			write(1, buf, len);
		ft_sha224_update(ctx, buf, len);
	}
	ft_sha224_final(digest, ctx);
	ft_sha224_digest_string(digest, digest_string);
	ft_sha_print("SHA224", NULL, digest_string, flags);
}
