/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:17:19 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:20:10 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

static void		fill_up_words
(
	t_byte4 w[FT_SHA256_BLOCK_SIZE]
)
{
	int i;

	i = 16;
	while (i < FT_SHA256_BLOCK_SIZE)
	{
		w[i] = SHA256_SIG1(w[i - 2]) + w[i - 7] +
				SHA256_SIG0(w[i - 15]) + w[i - 16];
		i++;
	}
}

static void		copy_from_registers
(
	t_sha256_ctx *from,
	t_temp_registers *to
)
{
	to->a = from->a;
	to->b = from->b;
	to->c = from->c;
	to->d = from->d;
	to->e = from->e;
	to->f = from->f;
	to->g = from->g;
	to->h = from->h;
}

static void		add_to_registers
(
	t_temp_registers *from,
	t_sha256_ctx *to
)
{
	to->a += from->a;
	to->b += from->b;
	to->c += from->c;
	to->d += from->d;
	to->e += from->e;
	to->f += from->f;
	to->g += from->g;
	to->h += from->h;
}

static void		main_transform_loop
(
	t_temp_registers *tr,
	t_byte4 w[FT_SHA256_BLOCK_SIZE]
)
{
	int		i;
	t_byte4	temp1;
	t_byte4	temp2;
	t_byte4	*k;

	k = ft_sha256_constants();
	i = 0;
	while (i < FT_SHA256_BLOCK_SIZE)
	{
		temp1 = tr->h + SHA256_SIGMA1(tr->e) +
						SHA_CH(tr->e, tr->f, tr->g) + k[i] + w[i];
		temp2 = SHA256_SIGMA0(tr->a) + SHA_MAJ(tr->a, tr->b, tr->c);
		tr->h = tr->g;
		tr->g = tr->f;
		tr->f = tr->e;
		tr->e = tr->d + temp1;
		tr->d = tr->c;
		tr->c = tr->b;
		tr->b = tr->a;
		tr->a = temp1 + temp2;
		i++;
	}
}

void			ft_sha256_transform
(
	t_sha256_ctx *c,
	t_byte1 block[FT_SHA256_BLOCK_SIZE]
)
{
	t_byte4				w[FT_SHA256_BLOCK_SIZE];
	t_temp_registers	tr;

	ft_sha256_decode(w, block);
	fill_up_words(w);
	copy_from_registers(c, &tr);
	main_transform_loop(&tr, w);
	add_to_registers(&tr, c);
}
