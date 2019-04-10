/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_set_raw_iv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:12:17 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 17:12:19 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void	ft_des_set_raw_iv
(
	t_des_ctx *ctx
)
{
	const char *wrong_char;

	wrong_char = ft_des_hex_to_bit(ctx->raw_iv, ctx->iv,
		FT_DES_BIT_BLOCK_SIZE);
	if (wrong_char)
		ft_des_print_error("wrong char in hex iinitialization vector");
}
