/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha256_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:33:33 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:33:43 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"
#include "libft.h"

static void	print_message(const char *algorithm, t_byte1 *message, int reverse)
{
	if (reverse)
	{
		ft_putstr(" ");
		ft_putstr((const char *)message);
	}
	else
	{
		ft_putstr(algorithm);
		ft_putstr(" (");
		ft_putstr((const char *)message);
		ft_putstr(") = ");
	}
}

void		ft_sha_print
(
	const char *algorithm,
	t_byte1 *target,
	t_byte1 *digest,
	t_sha_flags *flags
)
{
	if (target && !flags->quiet && flags->reverse)
	{
		ft_putstr((const char *)digest);
		print_message(algorithm, target, 1);
	}
	else if (target && !flags->quiet)
	{
		print_message(algorithm, target, 0);
		ft_putstr((const char *)digest);
	}
	else
		ft_putstr((const char *)digest);
	ft_putstr("\n");
	flags->something_printed = 1;
}
