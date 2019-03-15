#include "ft_des.h"

int	ft_des_key_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	t_byte1 key[FT_DES_INITIAL_KEY_SIZE] = {
		0, 1, 1, 0, 0, 0, 0, 1,
		0, 1, 1, 0, 0, 0, 1, 0,
		0, 1, 1, 0, 0, 0, 1, 1,
		0, 1, 1, 0, 0, 1, 0, 0,
		0, 1, 1, 0, 0, 0, 0, 1,
		0, 1, 1, 0, 0, 0, 1, 0,
		0, 1, 1, 0, 0, 0, 1, 1,
		0, 1, 1, 0, 0, 1, 0, 0,
	};
	int i;
	(void)argv;
	if (position + 1 >= argc)
		ft_des_print_error("there is no key after -k flag. type -h for help.");

	i = 0;
	while (i < FT_DES_INITIAL_KEY_SIZE)
	{
		ctx->key[i] = key[i];
		i++;
	}
	return (position + 2);
}