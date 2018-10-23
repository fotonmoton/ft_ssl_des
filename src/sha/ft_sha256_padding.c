/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:16:55 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:17:00 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"
#include "libft.h"

void	ft_sha256_padding(t_byte1 padding[FT_SHA256_BLOCK_SIZE])
{
	padding[0] = 0x80;
	ft_bzero(&padding[1], FT_SHA256_BLOCK_SIZE - 1);
}
