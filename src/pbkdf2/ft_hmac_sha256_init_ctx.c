/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmac_sha256_init_ctx.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:15:12 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:15:33 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_pbkdf2.h"
#include "ft_sha.h"
#include "libft.h"

void	ft_hmac_sha256_init_ctx
(
	t_hmac_sha256_ctx *ctx
)
{
	ctx->key = NULL;
	ctx->msg = NULL;
	ctx->key_size = 0;
	ctx->msg_size = 0;
	ft_bzero(ctx->opad, FT_SHA256_BLOCK_SIZE);
	ft_bzero(ctx->ipad, FT_SHA256_BLOCK_SIZE);
}
