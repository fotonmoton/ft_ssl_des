#include "ft_des.h"
#include <stddef.h>

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
	const char *wrong_key_char;

	if (position + 1 >= argc)
		ft_des_print_error("there is no key after -k flag. type -h for help.");
	wrong_key_char = ft_des_hex_to_bit_key(argv[position + 1], ctx->key);
	if (wrong_key_char != NULL)
		ft_des_print_error("there wrong char in key string.");
	return (position + 2);
}

int ft_des_decode_arg_parser
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

int ft_des_encode_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	(void)argc;
	(void)argv;
	ctx->encode = 1;
	return (++position);
}
