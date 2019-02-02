/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:30:28 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:30:30 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void	ft_md5_file(const char *filename, t_md5_flags *flags)
{
	int			fd;
	int			len;
	t_byte1		digest[FT_MD5_DIGEST_LENGTH_BYTE];
	t_md5_ctx	ctx;
	t_byte1		buf[FT_MD5_READ_BLOCK_SIZE];

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror("ft_ssl");
		exit(1);
	}
	ft_md5_init(&ctx);
	while ((len = read(fd, buf, FT_MD5_READ_BLOCK_SIZE)) > 0)
		ft_md5_update(&ctx, buf, len);
	ft_md5_final(digest, &ctx);
	ft_md5_print((t_byte1 *)filename, digest, flags);
}
