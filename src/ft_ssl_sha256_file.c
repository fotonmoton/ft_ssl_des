/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha256_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:33:03 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:33:23 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_sha.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void	ft_ssl_sha256_file(const char *filename, t_ft_ssl *ft_ssl)
{
	int				fd;
	int				len;
	t_byte1			digest[FT_SHA256_DIGEST_LENGTH_BYTE];
	t_sha256_ctx	ctx;
	t_byte1			buf[FT_SSL_BUFFER_SIZE];

	(void)ft_ssl;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror("./ft_ssl: ");
		exit(1);
	}
	ft_sha256_init(&ctx);
	while ((len = read(fd, buf, FT_SSL_BUFFER_SIZE)) > 0)
		ft_sha256_update(&ctx, buf, len);
	ft_sha256_final(digest, &ctx);
	ft_ssl_sha256_print(filename, digest, ft_ssl);
}
