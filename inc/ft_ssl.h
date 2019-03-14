/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:07:36 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 19:36:23 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

typedef void			(*t_alg_function)(int argc, char **argv);

typedef struct			s_alorithm
{
	const char			*name;
	t_alg_function		function;
}						t_algorithm;

void					ft_ssl_usage(void);
void					ft_ssl_init(int argc, char **argv);

#endif
