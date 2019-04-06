#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_des.h"
#include "ft_pbkdf2.h"
#include "libft.h"

static void get_pass
(
	char pass[128]
)
{
	char *first_try[128];
	char *second_try[128];

	ft_bzero(first_try, 128);
	ft_bzero(second_try, 128);
	ft_strcpy((char *)first_try, getpass("enter password:"));
	ft_strcpy((char *)second_try, getpass("retype password:"));
	if (ft_strcmp((const char *)first_try, (const char *)second_try) != 0)
		ft_des_print_error("passwords doesn't match");
	ft_strcpy(pass, (const char *)first_try);
}

static void	generate_salt
(
	char salt[FT_DES_BYTE_BLOCK_SIZE]
)
{
	int fd;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
	{
		perror("des");
		exit(1);
	}
	read(fd, salt, FT_DES_BYTE_BLOCK_SIZE);
}

static void	no_arguments
(
	t_des_ctx *ctx,
	t_pbkdf2_sha256_ctx *pbkdf_ctx
)
{
	char	pass[128];
	char	salt[FT_DES_BYTE_BLOCK_SIZE];
	t_byte1	key[FT_DES_BYTE_BLOCK_SIZE];

	get_pass(pass);
	generate_salt(salt);

	pbkdf_ctx->iterations = 10000;
	pbkdf_ctx->key = key;
	pbkdf_ctx->salt_len = FT_DES_BYTE_BLOCK_SIZE;
	pbkdf_ctx->pass = (t_byte1 *)pass;
	pbkdf_ctx->salt = (t_byte1 *)salt;
	pbkdf_ctx->pass_len = ft_strlen((char *)pass);
	pbkdf_ctx->key_len = FT_DES_BYTE_BLOCK_SIZE;
	ft_pbkdf2_sha256(pbkdf_ctx);
	ft_des_byte_to_bits(key, FT_DES_BYTE_BLOCK_SIZE, ctx->key,
	FT_DES_INITIAL_KEY_SIZE);
	write(ctx->output_fd, "Salted__", 8);
	write(ctx->output_fd, salt, FT_DES_BYTE_BLOCK_SIZE);
}

void	ft_des_derive_key
(
	t_des_ctx *ctx
)
{
	t_pbkdf2_sha256_ctx	pbkdf_ctx;
	t_byte1				key[FT_DES_BYTE_BLOCK_SIZE];

	if (!ctx->raw_key && !ctx->raw_salt && !ctx->raw_password)
	{
		no_arguments(ctx, &pbkdf_ctx);
		return ;
	}

	if (ctx->raw_key)
	{
		if (ft_des_hex_to_bit(ctx->raw_key, ctx->key, FT_DES_BIT_BLOCK_SIZE))
			ft_des_print_error("wrong char in key");
		return ;
	}
	// if (ctx->decode)
	// {
	// 	readed = read(ctx->input_fd, buffer, FT_DES_BYTE_BLOCK_SIZE);
	// 	if (readed != FT_DES_BYTE_BLOCK_SIZE)
	// 		ft_des_print_error("wrong input");
	// 	if (ft_strcmp("Salted__", buffer) == 0)
	// 	{
	// 		readed = read(ctx->input_fd, buffer, FT_DES_BYTE_BLOCK_SIZE);
	// 		if (readed != FT_DES_BYTE_BLOCK_SIZE)
	// 			ft_des_print_error("wrong salt");
	// 		pbkdf_ctx.salt = buffer;
	// 	}
	// 	else
	// 		ft_des_pr
	// }
	pbkdf_ctx.iterations = 10000;
	pbkdf_ctx.key = key;
	pbkdf_ctx.salt_len = FT_DES_BYTE_BLOCK_SIZE;
	pbkdf_ctx.pass = (t_byte1 *)ctx->raw_password;
	pbkdf_ctx.salt = ctx->salt;
	pbkdf_ctx.pass_len = ft_strlen((char *)ctx->raw_password);
	pbkdf_ctx.key_len = FT_DES_BYTE_BLOCK_SIZE;
	ft_pbkdf2_sha256(&pbkdf_ctx);
	ft_des_byte_to_bits(key, FT_DES_BYTE_BLOCK_SIZE, ctx->key,
	FT_DES_INITIAL_KEY_SIZE);
}