/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_switch_message_halves.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:12:41 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 17:12:47 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void	ft_des_switch_message_halves
(
	t_byte1 message[FT_DES_BIT_BLOCK_SIZE]
)
{
	int i;
	int tmp;

	i = 0;
	while (i < FT_DES_BIT_BLOCK_SIZE / 2)
	{
		tmp = message[i];
		message[i] = message[i + FT_DES_BIT_BLOCK_SIZE / 2];
		message[i + FT_DES_BIT_BLOCK_SIZE / 2] = tmp;
		i++;
	}
}
