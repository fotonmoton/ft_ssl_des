/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha256_stdin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:34:09 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:34:32 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_sha.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void	ft_ssl_sha256_stdin(t_ft_ssl *ft_ssl)
{
	int				len;
	t_byte1			digest[FT_SHA256_DIGEST_LENGTH_BYTE];
	t_sha256_ctx	ctx;
	t_byte1			buf[FT_SSL_BUFFER_SIZE];

	(void)ft_ssl;
	ft_sha256_init(&ctx);
	while ((len = read(0, buf, FT_SSL_BUFFER_SIZE)))
	{
		if (ft_ssl->flags.print_stdin)
			write(1, buf, len);
		ft_sha256_update(&ctx, buf, len);
	}
	ft_sha256_final(digest, &ctx);
	ft_ssl_sha256_print(NULL, digest, ft_ssl);
}
