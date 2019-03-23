#include "ft_des.h"
#include "libft.h"

t_des_argument_parser	g_arg_parsers[] = {
	{
		"-k",
		ft_des_key_arg_parser,
	},
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
	if (ctx.decode)
	{
		ft_des_generate_decryption_round_keys(ctx.key, ctx.round_keys);
		if (ctx.b64)
			ft_des_ecb_decrypt_b64(&ctx);
		else
			ft_des_ecb_decrypt(&ctx);
	}
	else
	{
		ft_des_generate_encryption_round_keys(ctx.key, ctx.round_keys);
		if (ctx.b64)
			ft_des_ecb_encrypt_b64(&ctx);
		else
			ft_des_ecb_encrypt(&ctx);
	}
	exit(0);
}