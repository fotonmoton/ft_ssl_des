/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:20:53 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:21:00 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"
#include "libft.h"

void	ft_sha256_update(t_sha256_ctx *c, t_byte1 *message, t_byte8 message_len)
{
	unsigned int i;
	unsigned int part_block_len;
	unsigned int curent_block_index;

	curent_block_index = (c->bit_len / 8) % 64;
	c->bit_len += message_len * 8;
	part_block_len = FT_SHA256_BLOCK_SIZE - curent_block_index;
	if (message_len >= part_block_len)
	{
		ft_memcpy(&c->block[curent_block_index], message, part_block_len);
		ft_sha256_transform(c, c->block);
		i = part_block_len;
		while (i + 63 < message_len)
		{
			ft_sha256_transform(c, &message[i]);
			i += FT_SHA256_BLOCK_SIZE;
		}
		curent_block_index = 0;
	}
	else
		i = 0;
	ft_memcpy(&c->block[curent_block_index], &message[i], message_len - i);
}
