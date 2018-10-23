/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_decode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:13:59 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:14:28 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

void	ft_sha256_decode
(
	t_byte4 w[FT_SHA256_WORDS_COUNT],
	t_byte1 b[FT_SHA256_BLOCK_SIZE]
)
{
	t_byte8 i;
	t_byte8 j;

	i = 0;
	j = 0;
	while (i < FT_SHA256_WORDS_COUNT)
	{
		w[i] = ((((t_byte4)b[j]) << 24) |
				(((t_byte4)b[j + 1]) << 16) |
				(((t_byte4)b[j + 2]) << 8) |
				((t_byte4)b[j + 3]));
		i++;
		j += 4;
	}
}
