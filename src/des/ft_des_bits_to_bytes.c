/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_bits_to_bytes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:20:55 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:21:03 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void	ft_des_bits_to_bytes
(
	t_byte1 *bits,
	t_byte8 bits_len,
	t_byte1 *bytes,
	t_byte8 bytes_len
)
{
	t_byte8 bits_count;
	t_byte8 bytes_count;

	bits_count = 0;
	bytes_count = 0;
	while (bits_count < bits_len && bytes_count < bytes_len)
	{
		bytes[bytes_count] = (bits[bits_count] << 7) |
			(bits[bits_count + 1] << 6) |
			(bits[bits_count + 2] << 5) |
			(bits[bits_count + 3] << 4) |
			(bits[bits_count + 4] << 3) |
			(bits[bits_count + 5] << 2) |
			(bits[bits_count + 6] << 1) |
			(bits[bits_count + 7]);
		bytes_count++;
		bits_count += 8;
	}
}
