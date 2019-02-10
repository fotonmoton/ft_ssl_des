/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_encode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:52:07 by gtertysh          #+#    #+#             */
/*   Updated: 2019/02/10 20:52:59 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_base64.h"
#include "libft.h"

void	ft_base64_encode(t_base64_ctx *ctx)
{
	t_byte1		buff[FT_BASE64_READ_SIZE + FT_BASE64_TRANS_SIZE];
	t_byte8		readed;
	t_byte8		reminder;
	int			fd;

	fd = ctx->input_fd;
	reminder = 0;
	while ((readed = read(fd, buff + reminder, FT_BASE64_READ_SIZE)) > 0)
	{
		if (readed >= FT_BASE64_TRANS_SIZE)
		{
			reminder = ft_base64_encode_step(ctx, readed, buff);
			ft_memmove(buff, buff + readed - reminder, reminder);
		}
		else
		{
			reminder += readed;
		}
	}
	// ft_base64_encode_finish(ctx, reminder, buff);
}
