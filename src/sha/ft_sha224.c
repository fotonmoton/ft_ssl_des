/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:42:15 by gtertysh          #+#    #+#             */
/*   Updated: 2019/02/03 18:42:42 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"
#include "libft.h"

static void		init_flags(t_sha_flags *flags)
{
	flags->quiet = 0;
	flags->print_stdin = 0;
	flags->reverse = 0;
	flags->something_printed = 0;
}

static int		read_flags(int argc, char **argv, t_sha_flags *flags)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp("-r", argv[i]) == 0)
			flags->reverse = 1;
		else if (ft_strcmp("-q", argv[i]) == 0)
			flags->quiet = 1;
		else if (ft_strcmp("-p", argv[i]) == 0)
			flags->print_stdin = 1;
		else
			break ;
		i++;
	}
	return (i);
}

static void		process_strings_and_files
(
	int argc,
	char **argv,
	t_sha_flags *flags,
	t_sha256_ctx *ctx
)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (ft_strcmp("-s", argv[i]) == 0)
		{
			if (i + 1 >= argc)
				ft_sha_usage("SHA224");
			ft_sha224_string(ctx, (t_byte1 *)argv[++i], flags);
			i++;
		}
		else
			ft_sha224_file(ctx, (t_byte1 *)argv[i++], flags);
	}
}

void			ft_sha224(int argc, char **argv)
{
	int				flags_readed;
	t_sha_flags		flags;
	t_sha256_ctx	ctx;

	init_flags(&flags);
	flags_readed = read_flags(argc, argv, &flags);
	if (flags.print_stdin)
		ft_sha224_stdin(&ctx, &flags);
	process_strings_and_files(
		argc - flags_readed, argv + flags_readed, &flags, &ctx);
	if (!flags.something_printed)
		ft_sha224_stdin(&ctx, &flags);
	exit(0);
}
