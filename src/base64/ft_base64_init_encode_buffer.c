/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_init_encode_buffer.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:12:46 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:12:48 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base64.h"
#include "libft.h"

void	ft_base64_init_encode_buffer
(
	t_base64_encode_buffer *buff
)
{
	ft_bzero(buff->block, FT_BASE64_ENCODE_BLOCK_SIZE);
	buff->readed = 0;
}
