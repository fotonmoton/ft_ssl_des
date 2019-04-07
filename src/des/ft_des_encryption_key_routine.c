#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_des.h"
#include "ft_pbkdf2.h"
#include "libft.h"

static void	derive_key
(
	t_des_ctx *ctx
)
{
	t_pbkdf2_sha256_ctx	pbkdf_ctx;
	t_byte1				byte_key[FT_DES_BYTE_BLOCK_SIZE];

	pbkdf_ctx.iterations = 10000;
	pbkdf_ctx.key = byte_key;
	pbkdf_ctx.salt_len = FT_DES_BYTE_BLOCK_SIZE;
	pbkdf_ctx.key_len = FT_DES_BYTE_BLOCK_SIZE;
	pbkdf_ctx.pass_len = ft_strlen((char *)ctx->raw_password);
	pbkdf_ctx.pass = (t_byte1 *)ctx->raw_password;
	pbkdf_ctx.salt = (t_byte1 *)ctx->salt;
	ft_pbkdf2_sha256(&pbkdf_ctx);
	ft_des_byte_to_bits(byte_key, FT_DES_BYTE_BLOCK_SIZE, ctx->key,
		FT_DES_INITIAL_KEY_SIZE);
}

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
	if (!ft_strlen((const char *)first_try))
		exit(1);
	ft_strcpy((char *)second_try, getpass("retype password:"));
	if (ft_strcmp((const char *)first_try, (const char *)second_try) != 0)
		ft_des_print_error("passwords doesn't match");
	ft_strcpy(pass, (const char *)first_try);
}

static void	get_salt
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

static void	get_key
(
	t_des_ctx *ctx
)
{
	const char *wrong_char;

	wrong_char = ft_des_hex_to_bit(ctx->raw_key, ctx->key,
		FT_DES_INITIAL_KEY_SIZE);
	if (wrong_char)
		ft_des_print_error("wrong char in hex key");
}

void	ft_des_encryption_key_routine
(
	t_des_ctx *ctx
)
{
	char	pass[128];

	if (ctx->raw_key)
	{
		get_key(ctx);
		return ;
	}
	if (!ctx->raw_password)
	{
		get_pass(pass);
		ctx->raw_password = pass;
	}
	if (!ctx->raw_salt)
		get_salt((char *)ctx->salt);
	derive_key(ctx);
}