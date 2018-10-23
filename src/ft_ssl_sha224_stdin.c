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

#include "ft_ssl.h"
#include "ft_sha.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void	ft_ssl_sha224_stdin(t_ft_ssl *ft_ssl)
{
	int				len;
	t_byte1			digest[FT_SHA224_DIGEST_LENGTH_BYTE];
	t_sha256_ctx	ctx;
	t_byte1			buf[FT_SSL_BUFFER_SIZE];

	(void)ft_ssl;
	ft_sha224_init(&ctx);
	while ((len = read(0, buf, FT_SSL_BUFFER_SIZE)))
	{
		if (ft_ssl->flags.print_stdin)
			write(1, buf, len);
		ft_sha224_update(&ctx, buf, len);
	}
	ft_sha224_final(digest, &ctx);
	ft_ssl_sha224_print(NULL, digest, ft_ssl);
}
