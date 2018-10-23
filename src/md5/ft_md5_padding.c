/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:50:37 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 19:50:42 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "libft.h"

void	ft_md5_padding(t_byte1 padding[FT_MD5_BLOCK_SIZE])
{
	padding[0] = 0x80;
	ft_bzero(&padding[1], FT_MD5_BLOCK_SIZE - 1);
}
