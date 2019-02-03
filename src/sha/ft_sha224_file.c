/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha224_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:30:48 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:31:18 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void	ft_sha224_file(t_sha256_ctx *ctx, t_byte1 *filename, t_sha_flags *flags)
{
	int				fd;
	int				len;
	t_byte1			buf[FT_SHA256_READ_BLOCK_SIZE];
	t_byte1			digest[FT_SHA224_DIGEST_LENGTH_BYTE];
	t_byte1			digest_string[FT_SHA224_STRING_SIZE_BYTE];

	ft_sha224_init(ctx);
	if ((fd = open((const char *)filename, O_RDONLY)) == -1)
	{
		perror("ft_ssl");
		exit(1);
	}
	while ((len = read(fd, buf, FT_SHA256_READ_BLOCK_SIZE)) > 0)
		ft_sha224_update(ctx, buf, len);
	ft_sha224_final(digest, ctx);
	ft_sha224_digest_string(digest, digest_string);
	ft_sha_print("SHA224", filename, digest_string, flags);
}
