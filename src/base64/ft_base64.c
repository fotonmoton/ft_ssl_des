/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:05:46 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:07:56 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_base64.h"

static void	usage(void)
{
	ft_putstr("base64 usage:\n");
	ft_putstr("ft_ssl base64 [-d|-e] [-i in_file] [-o out_file]\n\n");
	exit(1);
}

static int	open_input(char *filename)
{
	int			fd;
	struct stat	stat_buff;

	if ((fd = open((const char *)filename, O_RDONLY, 0)) == -1)
	{
		perror("base64: input stream error");
		exit(1);
	}
	stat(filename, &stat_buff);
	if (S_ISDIR(stat_buff.st_mode))
	{
		ft_putstr_fd("base64: input path is not a file", STDERR_FILENO);
		exit(1);
	}
	return (fd);
}

static int	open_output(char *filename)
{
	int fd;

	if ((fd = open((const char *)filename,
		O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) == -1)
	{
		perror("base64: output stream error");
		exit(1);
	}
	return (fd);
}

static void	read_args
(
	int argc,
	char **argv,
	t_base64_flags *flags,
	t_base64_ctx *ctx
)
{
	int		i;
	char	*current_arg;
	char	*next_arg;

	i = 0;
	while (i < argc)
	{
		current_arg = argv[i];
		next_arg = i + 1 < argc ? argv[i + 1] : NULL;
		if (ft_strcmp(current_arg, "-d") == 0)
			flags->decode = 1;
		else if (ft_strcmp(current_arg, "-e") == 0 && ++i)
			continue;
		else if (ft_strcmp(current_arg, "-i") == 0)
			ctx->input_fd = open_input(next_arg);
		else if (ft_strcmp(current_arg, "-o") == 0)
			ctx->output_fd = open_output(next_arg);
		else if (ft_strcmp(current_arg, "-h") == 0)
			usage();
		else if (++i)
			continue;
		i++;
	}
}

void		ft_base64(int argc, char **argv)
{
	t_base64_flags	flags;
	t_base64_ctx	ctx;

	flags.decode = 0;
	ft_base64_init(&ctx);
	read_args(argc, argv, &flags, &ctx);
	if (flags.decode)
		ft_base64_decode(&ctx);
	else
		ft_base64_encode(&ctx);
	exit(0);
}
