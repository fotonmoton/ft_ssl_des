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
	char	buffer[FT_DES_BYTE_BLOCK_SIZE];
	int		readed;

	readed = ft_des_buffered_read(c->input_fd, buffer, FT_DES_BYTE_BLOCK_SIZE);
	if (readed != FT_DES_BYTE_BLOCK_SIZE)
		ft_des_print_error("error reading input");
	if (ft_strncmp(buffer, "Salted__", FT_DES_BYTE_BLOCK_SIZE) != 0)
		ft_des_print_error("bad magic number");
	readed = ft_des_buffered_read(c->input_fd, buffer, FT_DES_BYTE_BLOCK_SIZE);
	if (readed != FT_DES_BYTE_BLOCK_SIZE)
	ft_des_print_error("error reading input");
	ft_memcpy(salt, buffer, FT_DES_BYTE_BLOCK_SIZE);
}

void	ft_des_decryption_key_routine
(
	t_des_ctx *ctx
)
{
	char salt[FT_DES_BYTE_BLOCK_SIZE];
	char pass[128];
	if (ctx->raw_password || !ctx->raw_key)
		get_salt(ctx, salt);
	if (!ctx->raw_password && !ctx->raw_key)
	{
		ft_des_get_password(pass);
		ctx->raw_password = pass;
		ft_des_derive_key_and_iv(ctx->key, ctx->iv, salt,
			 (char *)ctx->raw_password);
	}
	if (ctx->raw_key)
		ft_des_set_raw_key(ctx);
	if (ctx->raw_iv)
		ft_des_set_raw_iv(ctx);
}