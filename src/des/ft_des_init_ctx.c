/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_init_ctx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:46:08 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:46:12 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_des.h"
#include "libft.h"

void	ft_des_init_ctx
(
	t_des_ctx *ctx
)
{
	int i;

	i = 0;
	while (i < FT_DES_ROUND_COUNT)
	{
		ft_bzero(ctx->round_keys[i], FT_DES_ROUND_KEY_SIZE);
		i++;
	}
	ft_bzero(ctx->iv, FT_DES_BIT_BLOCK_SIZE);
	ft_bzero(ctx->key, FT_DES_BIT_BLOCK_SIZE);
	ft_bzero(ctx->buffer, FT_DES_BYTE_BLOCK_SIZE);
	ctx->readed = 0;
	ctx->decode = 0;
	ctx->b64 = 0;
	ctx->input_fd = STDIN_FILENO;
	ctx->output_fd = STDOUT_FILENO;
	ctx->raw_password = NULL;
	ctx->raw_salt = NULL;
	ctx->raw_key = NULL;
	ctx->raw_iv = NULL;
	ctx->encrypt = NULL;
	ctx->decrypt = NULL;
}
