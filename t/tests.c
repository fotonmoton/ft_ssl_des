/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:00:24 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 21:05:47 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"
#include "tests.h"

int all_tests()
{
	_verify("md5:", md5_tests);
	_verify("sha:", sha_tests);
	_verify("base64:", base64_tests);
	return 0;
}

int	main()
{
	int		result;

	result = all_tests();
	if (result == 0)
        printf("PASSED\n");

	return result != 0;
}
