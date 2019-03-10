/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:58:39 by gtertysh          #+#    #+#             */
/*   Updated: 2019/01/19 17:59:19 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DES_H
# define FT_DES_H

# define FT_DES_BIT_BLOCK_SIZE 64
# define FT_DES_EXPANDED_HALF_BLOCK_SIZE 48
# define FT_DES_S_BOX_SIZE 6

typedef unsigned char	t_byte1;

void					ft_des_initial_permutation
(
	t_byte1 message[FT_DES_BIT_BLOCK_SIZE],
	t_byte1 initial_permutation[FT_DES_BIT_BLOCK_SIZE]
);

void					ft_des_final_permutation
(
	t_byte1 before[FT_DES_BIT_BLOCK_SIZE],
	t_byte1 final_permutation[FT_DES_BIT_BLOCK_SIZE]
);

void					ft_des_expansion_box
(
	t_byte1 half[FT_DES_BIT_BLOCK_SIZE / 2],
	t_byte1 expanded[FT_DES_EXPANDED_HALF_BLOCK_SIZE]
);

#endif
