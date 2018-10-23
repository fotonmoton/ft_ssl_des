/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_encode_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:49:45 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 19:49:58 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void	ft_md5_encode_len(t_byte1 bits[FT_MD5_MESSAGE_LENGTH_BYTE], t_byte8 len)
{
	bits[0] = (t_byte1)(len & 0xff);
	bits[1] = (t_byte1)(len >> 8 & 0xff);
	bits[2] = (t_byte1)(len >> 16 & 0xff);
	bits[3] = (t_byte1)(len >> 24 & 0xff);
	bits[4] = (t_byte1)(len >> 32 & 0xff);
	bits[5] = (t_byte1)(len >> 40 & 0xff);
	bits[6] = (t_byte1)(len >> 48 & 0xff);
	bits[7] = (t_byte1)(len >> 56 & 0xff);
}
