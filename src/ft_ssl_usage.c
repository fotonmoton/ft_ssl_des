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
	ft_putstr("\n\nusage: \n");
	ft_putstr("ft_ssl algorithm [-p|-q|-r] [[-s string...] [file...]]\n\n");
	ft_putstr("algorithms:\n");
	ft_putstr("md5		sha256		sha224\n\n\n");
	exit(1);
}