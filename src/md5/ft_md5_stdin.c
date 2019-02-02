/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5_stdin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:29:11 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:29:38 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_md5.h"

void	ft_md5_stdin(t_md5_flags *flags)
{
	int			len;
	t_byte1		digest[FT_MD5_DIGEST_LENGTH_BYTE];
	t_md5_ctx	ctx;
	t_byte1		buf[FT_MD5_READ_BLOCK_SIZE];

	ft_md5_init(&ctx);
	while ((len = read(0, buf, FT_MD5_READ_BLOCK_SIZE)))
	{
		if (flags->print_stdin)
			write(1, buf, len);
		ft_md5_update(&ctx, buf, len);
	}
	ft_md5_final(digest, &ctx);
	ft_md5_print(NULL, digest, flags);
}
