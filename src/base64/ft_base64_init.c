/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:57:47 by gtertysh          #+#    #+#             */
/*   Updated: 2019/01/19 17:58:16 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base64.h"
#include "libft.h"

void	ft_base64_init(t_base64_ctx *ctx)
{
	ctx->block_bit_index = 0;
	ft_bzero(ctx->block, FT_BASE64_BLOCK_SIZE);
}
