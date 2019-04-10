/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:36:18 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:39:16 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_md5.h"
#include "ft_sha.h"
#include "ft_base64.h"
#include "ft_des.h"
#include "libft.h"

t_algorithm g_algorithms[] = {
	{
		"md5",
		ft_md5,
	},
	{
		"sha256",
		ft_sha256,
	},
	{
		"sha224",
		ft_sha224,
	},
	{
		"base64",
		ft_base64,
	},
	{
		"des",
		ft_des_cbc,
	},
	{
		"des-ecb",
		ft_des_ecb,
	},
	{
		"des-cbc",
		ft_des_cbc,
	},
	{
		"des-pcbc",
		ft_des_pcbc,
	},
	{NULL, NULL}
};

int			main(int argc, char **argv)
{
	char			*alg_name;
	t_algorithm		*alg_walker;

	alg_walker = g_algorithms;
	alg_name = argv[1];
	if (argc < 2)
		ft_ssl_usage();
	while (alg_walker->function)
	{
		if (ft_strcmp(alg_walker->name, alg_name) == 0)
			alg_walker->function(argc - 1, ++argv);
		alg_walker++;
	}
	ft_ssl_usage();
	return (0);
}
