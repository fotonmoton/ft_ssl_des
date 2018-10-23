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

#include "ft_ssl.h"
#include "ft_sha.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void	ft_ssl_sha224_string(const char *str, t_ft_ssl *ft_ssl)
{
	t_byte1			digest[FT_SHA224_DIGEST_LENGTH_BYTE];
	t_sha256_ctx	ctx;

	(void)ft_ssl;
	ft_sha224_init(&ctx);
	ft_sha224_update(&ctx, (unsigned char *)str, ft_strlen((const char *)str));
	ft_sha224_final(digest, &ctx);
	ft_ssl_sha224_print(str, digest, ft_ssl);
}
