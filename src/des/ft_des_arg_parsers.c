#include "ft_des.h"

int	ft_des_key_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	(void)ctx;
	(void)argv;
	if (position + 1 >= argc)
		ft_des_print_error("there is no key after -k flag. type -h for help.");
	return (position + 2);
}