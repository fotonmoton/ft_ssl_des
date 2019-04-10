/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_decode_finish.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:10:18 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:10:31 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_base64.h"
#include "libft.h"

void		ft_base64_decode_finish
(
	t_base64_decode_buffer *buff
)
{
	t_byte8 buffer_index;

	buffer_index = buff->readed % FT_BASE64_DECODE_BLOCK_SIZE;
	if (!buff->readed)
		return ;
	if (buffer_index != 0)
	{
		ft_putstr_fd("\nbase64: invalid input: readed \
bytes count isn't multiple of 4\n", STDERR_FILENO);
		exit(1);
	}
}
