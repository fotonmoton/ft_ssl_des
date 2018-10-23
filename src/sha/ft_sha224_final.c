/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224_final.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:11:43 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:11:47 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

void	ft_sha224_final
(
	t_byte1 digest[FT_SHA256_DIGEST_LENGTH_BYTE],
	t_sha256_ctx *ctx
)
{
	ft_sha256_final(digest, ctx);
}
