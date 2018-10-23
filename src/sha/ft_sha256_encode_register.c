/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_encode_register.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:15:49 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:15:52 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

void	ft_sha256_encode_register
(
	t_byte1 digest_part[FT_SHA256_REG_SIZE_BYTE],
	t_byte4 reg
)
{
	digest_part[0] = reg >> 24 & 0xff;
	digest_part[1] = reg >> 16 & 0xff;
	digest_part[2] = reg >> 8 & 0xff;
	digest_part[3] = reg & 0xff;
}
