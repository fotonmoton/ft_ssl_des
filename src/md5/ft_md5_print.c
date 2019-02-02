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
#include "libft.h"

static void	print_name(t_byte1 *name, int reverse)
{
	if (reverse)
	{
		ft_putstr(" ");
		ft_putstr((const char *)name);
	}
	else
	{
		ft_putstr("MD5 (");
		ft_putstr((const char *)name);
		ft_putstr(") = ");
	}
}

void		ft_md5_print
(
	t_byte1 *message,
	t_byte1 *digest,
	t_md5_flags *flags
)
{
	t_byte1 digest_string[FT_MD5_STRING_SIZE_BYTE];

	ft_md5_digest_string(digest, digest_string);
	if (message && !flags->quiet && flags->reverse)
	{
		ft_putstr((const char *)digest_string);
		print_name(message, 1);
	}
	else if (message && !flags->quiet)
	{
		print_name(message, 0);
		ft_putstr((const char *)digest_string);
	}
	else
		ft_putstr((const char *)digest_string);
	ft_putstr("\n");
	flags->something_printed = 1;
}
