/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_more_arg_parsers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:17:08 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 17:17:09 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "ft_des.h"

int	ft_des_input_file_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	struct stat stat_buff;

	if (position + 1 >= argc)
		ft_des_print_error("there is no filaname after -i flag.");
	if ((ctx->input_fd = open(argv[position + 1], O_RDONLY, 0)) == -1)
	{
		perror("des");
		exit(1);
	}
	stat(argv[position + 1], &stat_buff);
	if (S_ISDIR(stat_buff.st_mode))
		ft_des_print_error("input path is not a file.");
	return (position + 2);
}

int	ft_des_output_file_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	if (position + 1 >= argc)
		ft_des_print_error("there is no filaname after -o flag.");
	if ((ctx->output_fd = open(
		argv[position + 1], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) == -1)
	{
		perror("des");
		exit(1);
	}
	return (position + 2);
}

int	ft_des_password_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	if (position + 1 >= argc)
		ft_des_print_error("there is no password after -p flag.");
	ctx->raw_password = argv[position + 1];
	return (position + 2);
}

int	ft_des_salt_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	if (position + 1 >= argc)
		ft_des_print_error("there is no password after -p flag.");
	ctx->raw_salt = argv[position + 1];
	return (position + 2);
}

int	ft_des_help_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	(void)argc;
	(void)argv;
	(void)position;
	(void)ctx;
	ft_des_usage();
	return (position);
}
