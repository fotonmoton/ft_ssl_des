/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_set_raw_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:12:01 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 17:12:06 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

void	ft_des_set_raw_key
(
	t_des_ctx *ctx
)
{
	const char *wrong_char;

	wrong_char = ft_des_hex_to_bit(ctx->raw_key, ctx->key,
		FT_DES_BIT_BLOCK_SIZE);
	if (wrong_char)
		ft_des_print_error("wrong char in hex key");
}
