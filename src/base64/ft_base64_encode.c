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

void	ft_base64_encode(t_base64_ctx *c)
{
	t_byte1		buffer[FT_BASE64_READ_SIZE + FT_BASE64_TRANS_SIZE];
	t_byte8		readed;
	t_byte8		reminder;
	int			fd;

	reminder = 0;
	fd = c->input_fd;
	while ((readed = read(fd, buffer + reminder, FT_BASE64_READ_SIZE)) > 0)
	{
		if (readed + reminder >= FT_BASE64_TRANS_SIZE)
		{
			reminder = ft_base64_encode_step(c, readed + reminder, buffer);
			ft_memmove(buffer, buffer + readed - reminder, reminder);
		}
		else
		{
			reminder += readed;
		}

	}
	ft_base64_encode_finish(c, reminder, buffer);
}
