/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_generate_encryption_round_keys.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:44:32 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:44:40 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void	ft_des_generate_encryption_round_keys
(
	t_byte1 key[FT_DES_INITIAL_KEY_SIZE],
	t_byte1 round_keys[FT_DES_ROUND_COUNT][FT_DES_ROUND_KEY_SIZE]
)
{
	t_byte1	reduced_key[FT_DES_REDUCED_KEY_SIZE];
	int		i;

	ft_des_key_permuted_choice_one(key, reduced_key);
	i = 1;
	while (i <= FT_DES_ROUND_COUNT)
	{
		ft_des_derive_encryption_round_key(reduced_key, i, round_keys[i - 1]);
		i++;
	}
}
