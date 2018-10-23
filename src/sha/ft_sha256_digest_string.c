/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_digest_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:14:41 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:14:53 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

static void		init_chars(t_byte1 chars[16])
{
	chars[0] = '0';
	chars[1] = '1';
	chars[2] = '2';
	chars[3] = '3';
	chars[4] = '4';
	chars[5] = '5';
	chars[6] = '6';
	chars[7] = '7';
	chars[8] = '8';
	chars[9] = '9';
	chars[10] = 'a';
	chars[11] = 'b';
	chars[12] = 'c';
	chars[13] = 'd';
	chars[14] = 'e';
	chars[15] = 'f';
}

void			ft_sha256_digest_string
(
	t_byte1 digest[FT_SHA256_DIGEST_LENGTH_BYTE],
	t_byte1 string[FT_SHA256_STRING_SIZE_BYTE]
)
{
	t_byte8 i;
	t_byte8 j;
	t_byte1 chars[16];

	i = 0;
	j = 0;
	init_chars(chars);
	while (i < FT_SHA256_DIGEST_LENGTH_BYTE)
	{
		string[j] = chars[digest[i] / 16];
		string[j + 1] = chars[digest[i] % 16];
		i++;
		j += 2;
	}
	string[FT_SHA256_STRING_SIZE_BYTE - 1] = 0;
}
