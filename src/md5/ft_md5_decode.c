/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_decode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:48:18 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 19:49:27 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void	ft_md5_decode
(
		t_byte4 w[FT_MD5_WORDS_COUNT],
		t_byte1 b[FT_MD5_BLOCK_SIZE]
)
{
	t_byte8 i;
	t_byte8 j;

	i = 0;
	j = 0;
	while (j < FT_MD5_BLOCK_SIZE)
	{
		w[i] = ((t_byte4)b[j]) |
				(((t_byte4)b[j + 1]) << 8) |
				(((t_byte4)b[j + 2]) << 16) |
				(((t_byte4)b[j + 3]) << 24);
		i++;
		j += 4;
	}
}
