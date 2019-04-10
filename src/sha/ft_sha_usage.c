/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 22:04:39 by gtertysh          #+#    #+#             */
/*   Updated: 2019/02/03 22:04:41 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sha_usage(const char *algorithm)
{
	ft_putstr(algorithm);
	ft_putstr(" digest usage:\n");
	ft_putstr("ft_ssl ");
	ft_putstr(algorithm);
	ft_putstr(" [-p|-q|-r] [[-s string...] [file...]]\n\n");
	exit(1);
}
