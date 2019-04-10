/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_get_password.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:44:55 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:45:07 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"
#include "libft.h"

void	ft_des_get_password
(
	char pass[128]
)
{
	char first_try[128];
	char second_try[128];

	ft_bzero(first_try, 128);
	ft_bzero(second_try, 128);
	ft_strcpy(first_try, getpass("enter password:"));
	if (!ft_strlen(first_try))
		exit(1);
	ft_strcpy(second_try, getpass("retype password:"));
	if (ft_strcmp(first_try, second_try) != 0)
		ft_des_print_error("passwords doesn't match");
	ft_memcpy(pass, second_try, 128);
}
