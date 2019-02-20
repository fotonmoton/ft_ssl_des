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
	t_byte1					read_buff[FT_BASE64_READ_SIZE];
	t_base64_encode_buffer	enc_buff;
	int						readed;

	ft_base64_init_encode_buffer(&enc_buff);
	while ((readed = read(c->input_fd, read_buff, FT_BASE64_READ_SIZE)) > 0)
		ft_base64_encode_chunk(c, readed, read_buff, &enc_buff);
	ft_base64_encode_finish(c, &enc_buff);
}
