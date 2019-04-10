/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_arg_parsers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:18:18 by gtertysh          #+#    #+#             */
/*   Updated: 2019/04/10 16:20:51 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_des.h"

int	ft_des_base64_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	(void)argc;
	(void)argv;
	ctx->b64 = 1;
	return (++position);
}

int	ft_des_key_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	if (position + 1 >= argc)
		ft_des_print_error("there is no key after -k flag. type -h for help.");
	ctx->raw_key = argv[position + 1];
	return (position + 2);
}

int	ft_des_iv_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	if (position + 1 >= argc)
		ft_des_print_error("there is no initialization vector after -k flag. \
type -h for help.");
	ctx->raw_iv = argv[position + 1];
	return (position + 2);
}

int	ft_des_decode_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	(void)argc;
	(void)argv;
	ctx->decode = 1;
	return (++position);
}

int	ft_des_encode_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	(void)argc;
	(void)argv;
	ctx->decode = 0;
	return (++position);
}
