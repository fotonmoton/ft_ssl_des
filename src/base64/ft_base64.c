#include <stdio.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_base64.h"

static int	open_input(char *filename)
{
	int fd;
	struct stat stat_buff;

	if ((fd = open((const char *)filename, O_RDONLY, 0)) == -1)
	{
		perror("base64: input stream error");
		exit(1);
	}
	stat(filename, &stat_buff);
	if (S_ISDIR(stat_buff.st_mode))
	{
		ft_putstr_fd("base64: input path is not a file", STDERR_FILENO);
		exit(1);
	}
	return fd;
}

static int	open_output(char *filename)
{
	int fd;
	if ((fd = open((const char *)filename,
		O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) == -1)
	{
		perror("base64: output stream error");
		exit(1);
	}
	return fd;
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
		else if (ft_strcmp(current_arg, "-e") == 0 && ++i)
			continue;
		else if (ft_strcmp(current_arg, "-i") == 0)
			ctx->input_fd = open_input(next_arg);
		else if (ft_strcmp(current_arg, "-o") == 0)
			ctx->output_fd = open_output(next_arg);
		else if (++i)
			continue;
		i++;
	}
}

void		ft_base64(int argc, char **argv)
{
	t_base64_flags	flags;
	t_base64_ctx	ctx;

	init_flags(&flags);
	ft_base64_init(&ctx);
	read_args(argc, argv, &flags, &ctx);
	if (flags.decode)
		ft_base64_decode(&ctx);
	else
		ft_base64_encode(&ctx);
	exit(0);
}