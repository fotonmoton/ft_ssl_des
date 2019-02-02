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
	ft_putstr("Message Digest commands:\n");
	ft_putstr("md5\nsha256\nsha224\n\n");
	ft_putstr("Digest command usage:\n");
	ft_putstr("ft_ssl digest [-p|-q|-r] [[-s string...] [file...]]\n\n");
	ft_putstr("Cipher commands:\n");
	ft_putstr("base64\n");
	ft_putstr("Cipher command usage:\n");
	ft_putstr("ft_ssl cipher [-p|-q|-r] [[-s string...] [file...]]\n\n");
	exit(1);
}
