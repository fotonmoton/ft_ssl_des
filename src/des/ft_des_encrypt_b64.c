/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_encrypt_b64.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:33:39 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:34:06 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "ft_des.h"
#include "ft_base64.h"

static void	base64_encode
(
	t_des_ctx *ctx,
	int pipe_fd[2]
)
{
	t_base64_ctx b64_ctx;

	close(pipe_fd[1]);
	ft_base64_init(&b64_ctx);
	b64_ctx.output_fd = ctx->output_fd;
	b64_ctx.input_fd = pipe_fd[0];
	ft_base64_encode(&b64_ctx);
}

static void	des_encrypt
(
	t_des_ctx *ctx,
	int pipe_fd[2]
)
{
	close(pipe_fd[0]);
	ctx->output_fd = pipe_fd[1];
	ft_des_encrypt(ctx);
}

void		ft_des_encrypt_b64
(
	t_des_ctx *ctx
)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd))
		ft_des_print_error("failded to create pipe");
	pid = fork();
	if (pid == 0)
		des_encrypt(ctx, pipe_fd);
	else if (pid < 0)
		ft_des_print_error("failded to create child process");
	else
		base64_encode(ctx, pipe_fd);
}
