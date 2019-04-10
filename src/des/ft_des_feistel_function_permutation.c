/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_feistel_function_permutation.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:39:02 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:40:48 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void	ft_des_feistel_function_permutation
(
	t_byte1 input[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 output[FT_DES_BIT_BLOCK_SIZE / 2]
)
{
	static t_byte1	table[FT_DES_BIT_BLOCK_SIZE / 2] = {
	16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14,
	32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25,
	};
	int				i;

	i = 0;
	while (i < FT_DES_BIT_BLOCK_SIZE / 2)
	{
		output[i] = input[table[i] - 1];
		i++;
	}
}
