/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:57:47 by gtertysh          #+#    #+#             */
/*   Updated: 2019/01/19 17:58:16 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base64.h"
#include "libft.h"

void	ft_base64_init(t_base64_ctx *ctx)
{
	char	capital_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	lower_case[] = "abcdefghijklmnopqrstuvwxyz";
	char	rest[] = "0123456789+/";

	ft_bzero(ctx->block, FT_BASE64_BLOCK_SIZE);
	ft_bzero(ctx->chars, FT_BASE64_CHARS_SIZE);
	ft_memcpy(ctx->alphabet, capital_case, 26);
	ft_memcpy(ctx->alphabet + 26, lower_case, 26);
	ft_memcpy(ctx->alphabet + 52, rest, 12);

}
