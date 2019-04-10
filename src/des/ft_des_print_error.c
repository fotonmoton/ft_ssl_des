/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_print_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:54:22 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:54:25 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_des.h"
#include "libft.h"

void	ft_des_print_error
(
	const char *error
)
{
	ft_putstr_fd("des: ", STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(1);
}
