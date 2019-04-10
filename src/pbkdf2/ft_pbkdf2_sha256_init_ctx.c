/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pbkdf2_sha256_init_ctx.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:17:30 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:17:37 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_pbkdf2.h"

void	ft_pbkdf2_sha256_init_ctx
(
	t_pbkdf2_sha256_ctx *ctx
)
{
	ctx->iterations = 0;
	ctx->key = NULL;
	ctx->pass = NULL;
	ctx->salt = NULL;
	ctx->key_len = 0;
	ctx->pass_len = 0;
	ctx->salt_len = 0;
}
