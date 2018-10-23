/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_encode_register.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:52:22 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 19:52:32 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void	ft_md5_encode_register(t_byte1 *digest_part, t_byte4 reg)
{
	digest_part[0] = (t_byte1)(reg & 0xff);
	digest_part[1] = (t_byte1)(reg >> 8 & 0xff);
	digest_part[2] = (t_byte1)(reg >> 16 & 0xff);
	digest_part[3] = (t_byte1)(reg >> 24 & 0xff);
}
