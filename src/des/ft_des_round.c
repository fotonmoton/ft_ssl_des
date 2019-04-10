/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_round.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:13:31 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 17:13:43 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

static void	xor
(
	t_byte1 left_half[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 f_function_result[FT_DES_BIT_BLOCK_SIZE / 2]
)
{
	int i;

	i = 0;
	while (i < FT_DES_BIT_BLOCK_SIZE / 2)
	{
		left_half[i] = left_half[i] ^ f_function_result[i];
		i++;
	}
}

void		ft_des_round
(
	t_byte1 left_half[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 right_half[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 round_key[FT_DES_ROUND_KEY_SIZE]
)
{
	t_byte1 feistel_function_result[FT_DES_BIT_BLOCK_SIZE / 2];

	ft_des_feistel_function(right_half, round_key, feistel_function_result);
	xor(left_half, feistel_function_result);
}
