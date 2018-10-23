/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_encode_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:15:16 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:15:34 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

void	ft_sha256_encode_len
(
	t_byte1 b[FT_SHA256_MESSAGE_LENGTH_BYTE],
	t_byte8 len
)
{
	b[7] = (t_byte1)(len & 0xff);
	b[6] = (t_byte1)(len >> 8 & 0xff);
	b[5] = (t_byte1)(len >> 16 & 0xff);
	b[4] = (t_byte1)(len >> 24 & 0xff);
	b[3] = (t_byte1)(len >> 32 & 0xff);
	b[2] = (t_byte1)(len >> 40 & 0xff);
	b[1] = (t_byte1)(len >> 48 & 0xff);
	b[0] = (t_byte1)(len >> 56 & 0xff);
}
