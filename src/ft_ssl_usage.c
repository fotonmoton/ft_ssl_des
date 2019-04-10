/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:35:14 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:35:16 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

void	ft_ssl_usage(void)
{
	ft_putstr("\e[1;1H\e[2J");
	ft_putstr("Message Digest commands:\n");
	ft_putstr("md5\nsha256\nsha224\n\n");
	ft_putstr("Cipher commands:\n");
	ft_putstr("base64\ndes\ndes-ecb\ndes-cbc\ndes-pcbc\n\n");
	ft_putstr("To get help for specific command:\n");
	ft_putstr("ft_ssl command -h\n\n");
	exit(1);
}
