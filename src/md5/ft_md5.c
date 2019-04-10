/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 22:21:59 by gtertysh          #+#    #+#             */
/*   Updated: 2019/02/02 22:26:35 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "libft.h"

static void		ft_md5_usage(void)
{
	ft_putstr("md5 digest usage:\n");
	ft_putstr("ft_ssl md5 [-p|-q|-r] [[-s string...] [file...]]\n\n");
	exit(1);
}

static void		init_flags(t_md5_flags *flags)
{
	flags->quiet = 0;
	flags->print_stdin = 0;
	flags->reverse = 0;
	flags->something_printed = 0;
}

static int		read_flags(int argc, char **argv, t_md5_flags *flags)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp("-h", argv[i]) == 0)
			ft_md5_usage();
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
	int i,
	int argc,
	char **argv,
	t_md5_flags *flags
)
{
	while (i < argc)
	{
		if (ft_strcmp("-s", argv[i]) == 0)
		{
			if (i + 1 >= argc)
				ft_md5_usage();
			ft_md5_string(argv[++i], flags);
			i++;
		}
		else
			ft_md5_file(argv[i++], flags);
	}
}

void			ft_md5(int argc, char **argv)
{
	int			flags_readed;
	t_md5_flags	flags;

	init_flags(&flags);
	flags_readed = read_flags(argc, argv, &flags);
	if (flags.print_stdin)
		ft_md5_stdin(&flags);
	process_strings_and_files(flags_readed, argc, argv, &flags);
	if (!flags.something_printed)
		ft_md5_stdin(&flags);
	exit(0);
}
