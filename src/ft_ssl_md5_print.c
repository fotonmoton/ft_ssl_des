/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:28:46 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:28:58 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "ft_ssl.h"
#include "libft.h"

static void	print_name(const char *name, int reverse)
{
	if (reverse)
	{
		ft_putstr(" ");
		ft_putstr(name);
	}
	else
	{
		ft_putstr("MD5 (");
		ft_putstr(name);
		ft_putstr(") = ");
	}
}

void		ft_ssl_md5_print
(
	const char *target,
	unsigned char *digest,
	t_ft_ssl *ft_ssl
)
{
	t_byte1 digest_string[FT_MD5_STRING_SIZE_BYTE];

	ft_md5_digest_string(digest, digest_string);
	if (target && !ft_ssl->flags.quiet && ft_ssl->flags.reverse)
	{
		ft_putstr((const char *)digest_string);
		print_name(target, 1);
	}
	else if (target && !ft_ssl->flags.quiet)
	{
		print_name(target, 0);
		ft_putstr((const char *)digest_string);
	}
	else
		ft_putstr((const char *)digest_string);
	ft_putstr("\n");
	ft_ssl->flags.something_printed = 1;
}
