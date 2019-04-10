/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_encryption_key_routine.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:34:23 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:34:35 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "ft_des.h"
#include "libft.h"

static void	get_salt
(
	t_des_ctx *c,
	char salt[FT_DES_BYTE_BLOCK_SIZE]
)
{
	int			fd;

	if (c->raw_salt)
	{
		ft_bzero(salt, FT_DES_BYTE_BLOCK_SIZE);
		if (ft_des_hex_to_byte(c->raw_salt, (t_byte1 *)salt,
			FT_DES_BYTE_BLOCK_SIZE))
			ft_des_print_error("wrong char in salt");
	}
	else
	{
		fd = open("/dev/random", O_RDONLY);
		if (fd == -1)
		{
			perror("des");
			exit(1);
		}
		read(fd, salt, FT_DES_BYTE_BLOCK_SIZE);
		close(fd);
	}
}

void		ft_des_encryption_key_routine
(
	t_des_ctx *ctx
)
{
	char salt[FT_DES_BYTE_BLOCK_SIZE];
	char pass[128];

	if (ctx->raw_iv)
		ft_des_set_raw_iv(ctx);
	if (ctx->raw_key)
		ft_des_set_raw_key(ctx);
	else
	{
		if (!ctx->raw_password)
		{
			ft_des_get_password(pass);
			ctx->raw_password = pass;
		}
		get_salt(ctx, salt);
		ft_des_derive_key_and_iv(ctx->key, ctx->iv, salt,
			(char *)ctx->raw_password);
	}
	if (ctx->raw_password)
	{
		write(ctx->output_fd, "Salted__", 8);
		write(ctx->output_fd, salt, FT_DES_BYTE_BLOCK_SIZE);
	}
}
