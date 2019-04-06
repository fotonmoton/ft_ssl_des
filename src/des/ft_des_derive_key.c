#include <unistd.h>
#include "ft_des.h"
#include "ft_pbkdf2.h"
#include "libft.h"

void	ft_des_derive_key
(
	t_des_ctx *ctx
)
{
	t_pbkdf2_sha256_ctx	pbkdf_ctx;
	t_byte1				key[FT_DES_BYTE_BLOCK_SIZE];

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