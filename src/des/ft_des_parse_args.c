#include <stddef.h>
#include "ft_des.h"
#include "libft.h"

t_des_argument_parser	g_arg_parsers[] = {
	{
		"-d",
		ft_des_decode_arg_parser,
	},
	{
		"-e",
		ft_des_encode_arg_parser,
	},
	{
		"-a",
		ft_des_base64_arg_parser,
	},
	{
		"-i",
		ft_des_input_file_arg_parser,
	},
	{
		"-o",
		ft_des_output_file_arg_parser,
	},
	{
		"-k",
		ft_des_key_arg_parser,
	},
	{
		"-v",
		ft_des_iv_arg_parser,
	},
	{
		"-p",
		ft_des_password_arg_parser,
	},
	{
		"-s",
		ft_des_salt_arg_parser,
	},
	{
		"-h",
		ft_des_help_arg_parser,
	},
	{ NULL, NULL},
};

void	ft_des_parse_args
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
			ft_des_usage();
	}
}