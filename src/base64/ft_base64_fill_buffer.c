/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_fill_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:27:34 by gtertysh          #+#    #+#             */
/*   Updated: 2019/02/02 18:27:39 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_base64.h"

void	ft_base64_fill_buffer(t_base64_ctx *ctx, t_byte1 *data, t_byte8 size)
{
	ft_memcpy(ctx->glue_block, data, size);
	ctx->glue_block_bytes_count = size;
}
