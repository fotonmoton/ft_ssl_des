/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:12:56 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:13:12 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base64.h"
#include <unistd.h>

void		ft_base64_write(t_base64_ctx *ctx)
{
	write(ctx->output_fd, ctx->chars, FT_BASE64_CHARS_SIZE);
}
