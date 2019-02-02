/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:21:21 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:28:00 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

t_algorithm g_algorithms[] = {
	{
		"md5",
		ft_ssl_md5_stdin,
		ft_ssl_md5_file,
		ft_ssl_md5_string,
		DIGEST
	},
	{
		"sha256",
		ft_ssl_sha256_stdin,
		ft_ssl_sha256_file,
		ft_ssl_sha256_string,
		DIGEST
	},
	{
		"sha224",
		ft_ssl_sha224_stdin,
		ft_ssl_sha224_file,
		ft_ssl_sha224_string,
		DIGEST
	},
	{NULL, NULL, NULL, NULL, END}
};

static void			init_flags(t_ft_ssl *ft_ssl)
{
	ft_ssl->flags.print_stdin = 0;
	ft_ssl->flags.quiet = 0;
	ft_ssl->flags.reverse = 0;
	ft_ssl->flags.something_printed = 0;
}

static void			set_algorithm(t_algorithm *alg, t_ft_ssl *ft_ssl)
{
	ft_ssl->process_file = alg->process_file;
	ft_ssl->process_string = alg->process_string;
	ft_ssl->process_stdin = alg->process_stdin;
}

void				ft_ssl_init(char *alg_name, t_ft_ssl *ft_ssl)
{
	int			i;
	t_algorithm	*alg;
	t_algorithm	*alg_walker;

	i = 0;
	alg = 0;
	init_flags(ft_ssl);
	alg_walker = g_algorithms;
	while (alg_walker)
	{
		if (alg_walker[i].type == END)
			break ;
		if (ft_strcmp(alg_name, alg_walker[i].name) == 0)
		{
			alg = &alg_walker[i];
			break ;
		}
		i++;
	}
	if (!alg)
		ft_ssl_usage();
	set_algorithm(alg, ft_ssl);
}
