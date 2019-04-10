/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:18:03 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:18:15 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_des.h"

void		ft_des
(
	t_des_ctx *ctx
)
{
	if (ctx->decode)
	{
		if (ctx->b64)
			ft_des_decrypt_b64(ctx);
		else
			ft_des_decrypt(ctx);
	}
	else
	{
		if (ctx->b64)
			ft_des_encrypt_b64(ctx);
		else
			ft_des_encrypt(ctx);
	}
	exit(0);
}
