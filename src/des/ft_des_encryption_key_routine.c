#include <fcntl.h>
#include <stdio.h>
#include "ft_des.h"
#include "libft.h"

static void	get_salt
(
	t_des_ctx *c,
	char salt[FT_DES_BYTE_BLOCK_SIZE]
)
{
	int			fd;

	if (c->raw_salt)
	{
		ft_bzero(salt, FT_DES_BYTE_BLOCK_SIZE);
		if (ft_des_hex_to_byte(c->raw_salt, (t_byte1 *)salt,
			FT_DES_BYTE_BLOCK_SIZE))
			ft_des_print_error("wrong char in salt");
	}
	else
	{
		fd = open("/dev/random", O_RDONLY);
		if (fd == -1)
		{
			perror("des");
			exit(1);
		}
		read(fd, salt, FT_DES_BYTE_BLOCK_SIZE);
	}
}

void	ft_des_encryption_key_routine
(
	t_des_ctx *ctx
)
{
	char salt[FT_DES_BYTE_BLOCK_SIZE];

	if (ctx->raw_key)
		ft_des_set_raw_key(ctx);
	else
	{
		ft_des_get_password(ctx);
		get_salt(ctx, salt);
		ft_des_derive_key(ctx->key, salt, (char *)ctx->raw_password);
	}
	if (ctx->raw_password  || !ctx->raw_key)
	{
		write(ctx->output_fd, "Salted__", 8);
		write(ctx->output_fd, salt, FT_DES_BYTE_BLOCK_SIZE);
	}
}