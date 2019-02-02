/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_encode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:26:32 by gtertysh          #+#    #+#             */
/*   Updated: 2019/02/02 18:26:51 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_base64.h"

void	ft_base64_encode(t_base64_ctx *ctx, t_byte1 *data)
{
	t_byte1		first_char;
	t_byte1		second_char;
	t_byte1		third_char;
	t_byte1		fourth_char;

	first_char = (data[0] >> 2) & 0x3f;
	second_char = ((data[0] << 4) & 0x30) | ((data[1] >> 4) & 0xf);
	third_char = ((data[1] << 2) & 0x3c) | ((data[2] >> 6) & 0x3);
	fourth_char = data[2] & 0x3F;
	ctx->chars[0] = ctx->alphabet[first_char];
	ctx->chars[1] = ctx->alphabet[second_char];
	ctx->chars[2] = ctx->alphabet[third_char];
	ctx->chars[3] = ctx->alphabet[fourth_char];
}
