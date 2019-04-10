/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_key_permuted_choice_one.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:48:53 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:50:03 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void	ft_des_key_permuted_choice_one
(
	t_byte1 initial_key[FT_DES_INITIAL_KEY_SIZE],
	t_byte1 reduced_key[FT_DES_REDUCED_KEY_SIZE]
)
{
	static t_byte1	table[FT_DES_REDUCED_KEY_SIZE] = {
		57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43,
		35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62,
		54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4,
	};
	int				i;

	i = 0;
	while (i < FT_DES_REDUCED_KEY_SIZE)
	{
		reduced_key[i] = initial_key[table[i] - 1];
		i++;
	}
}
