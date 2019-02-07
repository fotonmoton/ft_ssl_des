#include "libft.h"
#include "ft_base64.h"

static void	open_input_stream(t_base64_ctx *ctx, char *filename)
{
	(void)ctx;
	(void)filename;
}

static void	open_output_stream(t_base64_ctx *ctx, char *filename)
{
	(void)ctx;
	(void)filename;
}

static void	init_flags(t_base64_flags *flags)
{
	flags->decode = 0;
}

static void read_args
(
	int argc,
	char **argv,
	t_base64_flags *flags,
	t_base64_ctx *ctx
)
{
	int i;
	char *current_arg;
	char *next_arg;

	i = 0;
	while(i < argc)
	{
		current_arg = argv[i];
		next_arg = i + 1 < argc ? argv[i + 1] : NULL;
		if (ft_strcmp(current_arg, "-d") == 0)
			flags->decode = 1;
		else if (ft_strcmp(current_arg, "-e") == 0 && i++)
			continue;
		else if (ft_strcmp(current_arg, "-i") == 0)
			open_input_stream(ctx, next_arg);
		else if (ft_strcmp(current_arg, "-o") == 0)
			open_output_stream(ctx, next_arg);
		else if (i++)
			continue;
		i++;
	}
}

void		ft_base64(int argc, char **argv)
{
	t_base64_flags	flags;
	t_base64_ctx	ctx;

	init_flags(&flags);
	read_args(argc, argv, &flags, &ctx);
	if (flags.decode)
		ft_base64_decode(&ctx);
	else
		ft_base64_encode(&ctx);
	exit(0);
}