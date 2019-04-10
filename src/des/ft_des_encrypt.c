/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_encrypt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:33:05 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:33:11 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_des.h"
#include "ft_base64.h"

void	ft_des_encrypt
(
	t_des_ctx *ctx
)
{
	t_byte1					buffer[FT_DES_READ_SIZE];
	t_byte8					readed;

	ft_des_encryption_key_routine(ctx);
	ft_des_generate_encryption_round_keys(ctx->key, ctx->round_keys);
	while ((readed = read(ctx->input_fd, buffer, FT_DES_READ_SIZE)) > 0)
		ft_des_encode_process_chunk(ctx, readed, buffer);
	ft_des_finish_encrypt(ctx);
}
