/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:57:47 by gtertysh          #+#    #+#             */
/*   Updated: 2019/02/02 18:29:20 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base64.h"
#include "libft.h"

void	ft_base64_init(t_base64_ctx *ctx)
{
	ctx->glue_block_bytes_count = 0;
	ft_bzero(ctx->glue_block, FT_BASE64_GLUE_BLOCK_SIZE);
	ft_bzero(ctx->chars, FT_BASE64_CHARS_SIZE);
	ft_memcpy(ctx->alphabet, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);
	ft_memcpy(ctx->alphabet + 26, "abcdefghijklmnopqrstuvwxyz", 26);
	ft_memcpy(ctx->alphabet + 52, "0123456789+/", 12);
}
