#include "ft_des.h"
#include "libft.h"

t_des_argument_parser	g_arg_parsers[] = {
	{
		"-k",
		ft_des_key_arg_parser,
	},
	{ NULL, NULL},
};

static void	parse_args
(
	int argc,
	char **argv,
	t_des_ctx *ctx
)
{
	int i;
	char *current_arg;
	t_des_argument_parser *parser_walker;

	i = 1;
	while(i < argc)
	{
		current_arg = argv[i];
		parser_walker = g_arg_parsers;
		while(parser_walker->arg_parser)
		{
			if (ft_strcmp(current_arg, parser_walker->arg) == 0)
			{
				i = parser_walker->arg_parser(argc, argv, i, ctx);
				break;
			}
			parser_walker++;
		}
		if (!parser_walker->arg_parser)
			ft_des_print_error("wrong argument. type -h for help.");
	}
}

void		ft_des_ecb
(
	int argc,
	char **argv
)
{
	t_des_ctx	ctx;

	ft_des_init_ctx(&ctx);
	parse_args(argc, argv, &ctx);
	ft_des_ecb_process(&ctx);
	exit(0);
}