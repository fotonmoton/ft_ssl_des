#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
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
	ctx->decode = 0;
	return (++position);
}

int ft_des_input_file_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	struct stat stat_buff;

	if (position + 1 >= argc)
		ft_des_print_error("there is no filaname after -i flag.");
	if ((ctx->input_fd = open(argv[position + 1], O_RDONLY, 0)) == -1)
	{
		perror("des");
		exit(1);
	}
	stat(argv[position + 1], &stat_buff);
	if (S_ISDIR(stat_buff.st_mode))
		ft_des_print_error("input path is not a file.");
	return (position + 2);
}

int ft_des_output_file_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	if (position + 1 >= argc)
		ft_des_print_error("there is no filaname after -o flag.");
	if ((ctx->output_fd = open(
		argv[position + 1], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) == -1)
	{
		perror("des");
		exit(1);
	}
	return (position + 2);
}

int ft_des_password_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	if (position + 1 >= argc)
		ft_des_print_error("there is no password after -p flag.");
	ctx->raw_password = argv[position + 1];
	return (position + 2);
}

int ft_des_salt_arg_parser
(
	int argc,
	char **argv,
	int position,
	t_des_ctx *ctx
)
{
	if (position + 1 >= argc)
		ft_des_print_error("there is no password after -p flag.");
	ctx->raw_salt = argv[position + 1];
	return (position + 2);
}
