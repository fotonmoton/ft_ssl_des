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
	t_byte1		buffer[FT_BASE64_READ_SIZE];
	int			readed;
	int			head;
	int			reminder;

	reminder = 0;
	head = 0;
	while ((readed = read(c->input_fd, buffer, FT_BASE64_READ_SIZE)) > 0)
		ft_base64_chunk(c, readed, buffer);
	ft_base64_encode_finish(c, reminder, buffer);
}
